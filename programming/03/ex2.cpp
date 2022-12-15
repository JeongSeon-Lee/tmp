#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int start[100], end[100];
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &start[i], &end[i]);
	}

	int i, j;
	for (i = n - 1; i >= 0; i--) {
		int idx_max = 0;
		for (j = 1; j <= i; j++) {
			if (start[j] > start[idx_max] || start[j] == start[idx_max] && end[j] > end[idx_max]) {
				idx_max = j;
			}
		}
        int tmp = start[i];
        start[i] = start[idx_max];
        start[idx_max] = tmp;

        tmp = end[i];
        end[i] = end[idx_max];
        end[idx_max] = tmp;
	}

	for (i = 0; i < n; i++) {
		printf("%d %d\n", start[i], end[i]);
	}

	return 0;
}