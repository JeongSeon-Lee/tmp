#include <stdio.h>
#include "queueADT.h"
#include "pos.h"

#define MAX 100

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

7
0 0 0 0 1 0 0
0 1 1 0 1 0 1
0 0 1 0 0 0 0
1 0 1 1 1 1 1
0 0 0 0 1 0 0
1 0 1 1 1 1 0
0 0 0 0 0 0 0
*/

void read_maze();
void print_maze();
bool movable(Position pos, int dir);

int main() {
	scanf_s("%d", &n);
	read_maze();

	Queue queue = create();
	Position cur;
	cur.x = 0;
	cur.y = 0;

	enqueue(queue, cur);

	maze[0][0] = -1;	// 추가 배열을 쓰지 않기 위해 방문 표시를 음수로 저장한다.

	while (!is_empty(queue)) {
		Position cur = dequeue(queue);
		for (int dir = 0; dir < 4; dir++) {
			if (movable(cur, dir)) {
				Position p = move_to(cur, dir);
				maze[p.x][p.y] = maze[cur.x][cur.y] - 1;	// 추가 배열을 쓰지 않기 위해 방문 표시를 음수로 저장한다.
				if (p.x == n - 1 && p.y == n - 1) {
					break;
				}
				enqueue(queue, p);
			}
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
		maze[tmp.x][tmp.y] != 0)
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