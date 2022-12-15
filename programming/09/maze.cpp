#include <stdio.h>
#include "stackADT.h"
#include "pos.h"

#define MAX 50
#define BACKGROUND 0
#define IMAGE 1
#define VISITED 2
#define BACKTRACKED 3

int maze[MAX][MAX];
int n;

void read_maze(FILE* fp);
int sol_maze(Position cur);
bool movable(Position pos, int dir);

int main(void) {
	FILE* fp = 0;
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL)
		printf("파일 오픈 실패");

	int t;
	fscanf_s(fp, "%d", &t);
	for (int i = 0; i < t; i++) {
		fscanf_s(fp, "%d", &n);
		read_maze(fp);
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (maze[x][y] == 1) {
					Position cur;
					cur.x = x;
					cur.y = y;
					int component_size = sol_maze(cur);
					printf("%d ", component_size);
				}
			}
		}
		printf("\n");
	}
}

void read_maze(FILE* fp) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fscanf_s(fp, "%d", &maze[i][j]);
}

int sol_maze(Position cur) {
	Stack s = create();
	int count = 0;
	while (1) {
		if (maze[cur.x][cur.y] == 1)
			count++;
		maze[cur.x][cur.y] = VISITED;
		bool forwarded = false;
		for (int dir = 0; dir < 8; dir++) {
			if (movable(cur, dir)) {
				push(s, cur);
				cur = move_to(cur, dir);
				forwarded = true;
				break;
			}
		}
		if (!forwarded) {
			maze[cur.x][cur.y] = BACKTRACKED;
			if (is_empty(s))
				return count;
			cur = pop(s);
		}
	}
}

bool movable(Position pos, int dir) {
	Position tmp = move_to(pos, dir);
	if (tmp.x < 0 || tmp.x > n - 1 ||
		tmp.y < 0 || tmp.y > n - 1 ||
		maze[tmp.x][tmp.y] != 1)
		return false;
	return true;
}