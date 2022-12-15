#include <stdio.h>
#include <stdlib.h>
#define N 4

int cols[N + 1];

bool promising(int level);

bool queens(int level)
{
	if (!promising(level))
		return false;
	else if (level == N) {
		for (int i = 1; i <= N; i++) {
			printf("(%d, %d)\n", i, cols[i]);
		}
		return true;
	}
	for (int i = 1; i <= N; i++) {
		cols[level + 1] = i;
		if (queens(level + 1))
			return true;
	}
	return false;
}

bool promising(int level)
{
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level])
			return false;
		else if(level - i == abs(cols[level] - cols[i]))
			return false;
	}
}

int main(void)
{
	queens(0);
	return 0;
}