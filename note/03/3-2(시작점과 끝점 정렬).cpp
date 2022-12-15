/* 2. 입력으로 100개 미만 n개의 구간(interval)이 주어진다. 각 구간은 구간의 시작점과 끝점으로 표현된다. 이
구간들을 시작점이 빠른 순서대로 정렬하여 출력하는 프로그램을 작성하라. 시작점이 같은 경우 끝점
이 빠른 것을 먼저 출력한다. 입력 형식은 먼저 n의 값이 주어지고, 이어서 각 구간의 시작점과 끝점이
차례대로 주어진다. 각 구간의 시작점과 끝점은 정수이고, 끝점은 항상 시작점보다 크거나 같다. */

#include <stdio.h>

int main(void)
{
	int n;
	scanf_s("%d", &n);
	int start[100], end[100];
	for (int i = 0; i < n; i++) {
		scanf_s("%d%d", &start[i], &end[i]);
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

//void bubblesort(int n, int num1[], int num2[])
//{
//	int tmp;
//	for (int i = n - 1; i > 0; i--) {
//		for (int j = 0; j < i; j++) {
//			if (num1[j] > num1[j + 1] || num1[j] == num1[j + 1] && num2[j] > num2[j + 1]) {
//				if (num1[j] != num1[j + 1]) {
//					tmp = num1[j];
//					num1[j] = num1[j + 1];
//					num1[j + 1] = tmp;
//				}
//				tmp = num2[j];
//				num2[j] = num2[j + 1];
//				num2[j + 1] = tmp;
//			}
//		}
//	}
//}