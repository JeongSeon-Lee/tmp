/* 통과 완료 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ary[100];
	int n;
	int i, j, count = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &ary[i]);
	}
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (ary[i] > ary[j]) {
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}