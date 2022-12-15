#include <stdio.h>

int main(void)
{
	int data[100];
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	int i, j;
	for (i = n - 1; i >= 0; i--) {
		int idx_max = 0;
		for (j = 1; j <= i; j++) {
			if (data[j] > data[idx_max]) {
				idx_max = j;
			}
		}
		if (data[i] != data[idx_max]) {
			int tmp = data[i];
			data[i] = data[idx_max];
			data[idx_max] = tmp;
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}

	return 0;
}