/* 통과 완료 */
#include <stdio.h>

#define PATHWAY_COLOUR 0
#define WALL_COLOUR 1
#define BLOCKED_COLOUR 2
#define PATH_COLOUR 3

int n = 9;
int maze[][9] = {
	{0, 0, 0, 0, 0, 0, 0, 1, 0},
	{0, 1, 1, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 1, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 0, 0, 0, 1, 0, 1, 0},
	{0, 0, 0, 1, 0, 0, 0, 1, 0},
	{0, 1, 1, 1, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int xOffset[4] = { -1, 0, 1, 0 };
int yOffset[4] = { 0, 1, 0, -1 };

int mazePathCount(int x, int y);
bool promising(int x, int y);

int main()
{
	printf("%d\n", mazePathCount(0, 0));
	return 0;
}

int mazePathCount(int x, int y)
{
	if (!promising(x, y))
		return 0;
	else if (x == n - 1 && y == n - 1) {
		maze[x][y] = PATHWAY_COLOUR;
		return 1;
	}
	int sum = 0;
	maze[x][y] = PATH_COLOUR;
	for (int i = 0; i < 4; i++) {
		sum += mazePathCount(x + xOffset[i], y + yOffset[i]);
	}
	maze[x][y] = BLOCKED_COLOUR;
	return sum;
}

bool promising(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] != PATHWAY_COLOUR)
		return false;
	return true;
}