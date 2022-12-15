#include <stdio.h>

int n = 8;
//int maze[][8] = {
//	{0, 0, 0, 0, 0, 0, 0, 1},
//	{0, 1, 1, 0, 1, 1, 0, 1},
//	{0, 0, 0, 1, 0, 0, 0, 1},
//	{0, 1, 0, 0, 1, 1, 0, 0},
//	{0, 1, 1, 1, 0, 0, 1, 1},
//	{0, 1, 0, 0, 0, 1, 0, 1},
//	{0, 0, 0, 1, 0, 0, 0, 1},
//	{0, 1, 1, 1, 0, 1, 0, 0}
//};
int maze[][8] = {
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1},
	{0, 1, 1, 1, 1, 1, 1, 1},
	{0, 1, 1, 1, 1, 1, 1, 1},
	{0, 1, 1, 1, 1, 1, 1, 1},
	{0, 1, 1, 1, 1, 1, 1, 1},
	{0, 1, 1, 1, 1, 1, 1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0}
};

#define PATHWAY_COLOUR 0
#define WALL_COLOUR 1
#define BLOCKED_COLOUR 2
#define PATH_COLOUR 3

int findMazePath(int x, int y, int dist) {
	if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] != PATHWAY_COLOUR)
		return -1;
	else if (x == n - 1 && y == n - 1) {
		maze[x][y] = PATH_COLOUR;
		printf("Found the path.\n");
		return dist;
	}
	else {
		maze[x][y] = PATH_COLOUR;
		if (findMazePath(x - 1, y, dist + 1) >= 0 || findMazePath(x, y + 1, dist + 1) >= 0 || findMazePath(x + 1, y, dist + 1) >= 0 || findMazePath(x, y - 1, dist + 1) >= 0) {
			printf("%d ", dist + 1);
			return dist + 1;
		}
		maze[x][y] = BLOCKED_COLOUR;
		return -1;
	}
}

void printMaze(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	printMaze();
	printf("%d\n", findMazePath(0, 0, 0));
	printMaze();
	return 0;
}