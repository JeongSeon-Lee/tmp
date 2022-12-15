#include <stdio.h>

void bubblesort(int n, int num1[], int num2[]);

int main(void)
{
	int n;
	scanf_s("%d", &n);
	int start[100], end[100];
	for (int i = 0; i < n; i++) {
		scanf_s("%d%d", &start[i], &end[i]);
	}

	bubblesort(n, start, end);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", start[i], end[i]);
	}

	return 0;
}

void bubblesort(int n, int num1[], int num2[])
{
	int tmp;
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (num1[j] > num1[j + 1] || num1[j] == num1[j + 1] && num2[j] > num2[j + 1]) {
				if (num1[j] != num1[j + 1]) {
					tmp = num1[j];
					num1[j] = num1[j + 1];
					num1[j + 1] = tmp;
				}
				tmp = num2[j];
				num2[j] = num2[j + 1];
				num2[j + 1] = tmp;
			}
		}
	}
}