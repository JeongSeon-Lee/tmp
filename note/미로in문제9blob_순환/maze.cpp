#include <stdio.h>

#define MAX 50
#define BACKGROUND 0
#define IMAGE 1
#define ALREADY_COUNTED 2
#define BACKTRACKED 3

int maze[MAX][MAX];
int n;

void read_maze(FILE* fp);
int countCells(int x, int y);

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
					printf("%d ", countCells(x, y));
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

int countCells(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n || maze[x][y] != IMAGE)
		return 0;
	else {
		maze[x][y] = ALREADY_COUNTED;
		return 1 + countCells(x - 1, y + 1) + countCells(x, y + 1)
			+ countCells(x + 1, y + 1) + countCells(x - 1, y)
			+ countCells(x + 1, y) + countCells(x - 1, y - 1)
			+ countCells(x, y - 1) + countCells(x + 1, y - 1);
	}
}