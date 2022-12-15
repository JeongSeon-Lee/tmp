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

	int init_dir = 0;	// � ��ġ�� �������� �� ó������ �õ��� �� �̵� ����

	while (1) {
		maze[cur.x][cur.y] = VISITED;
		if (cur.x == n - 1 && cur.y == n - 1) {
			printf("Found the path.\n");
			break;
		}
		bool forwarded = false;		// 4���� �� �� ������ �����ϴµ� �����ߴ����� ǥ���Ѵ�.
		for (int dir = init_dir; dir < 4; dir++) {
			if (movable(cur, dir)) {
				push(s, dir);	// ���ÿ��� ���� ��ġ ��� �̵��ϴ� ������ push
				cur = move_to(cur, dir);
				forwarded = true;
				init_dir = 0;	// ó�� �湮�ϴ� ��ġ������ �׻� 0�� ������� �õ��� ����.
				break;
			}
		}
		if (!forwarded) {
			maze[cur.x][cur.y] = BACKTRACKED;
			if (is_empty(s)) {	// �ǵ��ư� ��ġ�� ���ٸ� ���� �ⱸ�� ���� �̷�
				printf("No path exists.\n");
				break;
			}
			
			int d = pop(s);
			cur = move_to(cur, (d + 2) % 4);	// �ǵ��ư� ����

			init_dir = d + 1;	// �ǵ��� �� ��ġ������ d + 1�� ������� �õ��غ��� �ȴ�.
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