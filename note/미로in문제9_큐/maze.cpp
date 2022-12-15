#include <stdio.h>
#include "queueADT_circular.h"
#include "pos.h"

#define MAX 50
#define VISITED 2

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
					Position start;
					start.x = x;
					start.y = y;
					int component_size = sol_maze(start);
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

int sol_maze(Position start) {
	Queue queue = create();
	enqueue(queue, start);
	maze[start.x][start.y] = VISITED;
	int count = 1;
	while (!is_empty(queue)) {
		Position cur = dequeue(queue);
		for (int dir = 0; dir < 8; dir++) {
			if (movable(cur, dir)) {
				Position p = move_to(cur, dir);
				maze[p.x][p.y] = VISITED;	// 추가 배열을 쓰지 않기 위해 방문 표시를 음수로 저장한다.
				count++;
				enqueue(queue, p);
			}
		}
	}
	return count;
}

bool movable(Position pos, int dir) {
	Position tmp = move_to(pos, dir);
	if (tmp.x < 0 || tmp.x > n - 1 ||
		tmp.y < 0 || tmp.y > n - 1 ||
		maze[tmp.x][tmp.y] != 1)
		return false;
	return true;
}
