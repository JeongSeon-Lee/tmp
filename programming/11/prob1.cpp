/* 통과 완료 */
#include <stdio.h>
#include <stdlib.h>

int cols[16];

int queens(int level, int n);
bool promising(int level);

int main(void)
{
	for (int n = 1; n <= 15; n++) {
		printf("N = %d: %d\n", n, queens(0, n));
	}
	return 0;
}

int queens(int level, int n)
{
	if (!promising(level))
		return 0;
	else if (level == n)
		return 1;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cols[level + 1] = i;
		sum += queens(level + 1, n);
	}
	return sum;
}

bool promising(int level)
{
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level])
			return false;
		else if (level - i == abs(cols[level] - cols[i]))
			return false;
	}
	return true;
}