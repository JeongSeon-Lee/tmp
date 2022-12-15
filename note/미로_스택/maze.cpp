#include <stdio.h>
#include "stackADT.h"
#include "pos.h"

#define MAX 100
#define PATH 0
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3

int maze[MAX][MAX];
int n;

/*
8
0 0 0 0 1 0 0 0
0 1 1 0 1 0 1 1
0 0 1 0 0 0 0 0
1 0 1 1 1 1 1 1
0 0 0 0 0 0 0 1
1 0 1 1 1 1 0 1
0 0 0 0 0 0 0 0
0 1 1 1 0 0 0 0
*/

void read_maze();
void print_maze();
bool movable(Position pos, int dir);

int main() {
	scanf_s("%d", &n);
	read_maze();

	Stack s = create();
	Position cur;
	cur.x = 0;
	cur.y = 0;

	while (1) {
		maze[cur.x][cur.y] = VISITED;
		if (cur.x == n - 1 && cur.y == n - 1) {
			printf("Found the path.\n");
			break;
		}
		bool forwarded = false;		// 4방향 중 한 곳으로 전진하는데 성공했는지를 표시한다.
		for (int dir = 0; dir < 4; dir++) {
			if (movable(cur, dir)) {
				push(s, cur);
				cur = move_to(cur, dir);
				forwarded = true;
				break;
			}
		}
		if (!forwarded) {
			maze[cur.x][cur.y] = BACKTRACKED;
			if (is_empty(s)) {	// 되돌아갈 위치가 없다면 원래 출구가 없는 미로
				printf("No path exists.\n");
				break;
			}
			cur = pop(s);
		}
	}

	print_maze();
}

void read_maze() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &maze[i][j]);
		}
	}
}

bool movable(Position pos, int dir) {
	Position tmp = move_to(pos, dir);
	if (tmp.x < 0 || tmp.x > n - 1 ||
		tmp.y < 0 || tmp.y > n - 1 ||
		maze[tmp.x][tmp.y] > 0)
		return false;
	return true;
}

void print_maze() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
}