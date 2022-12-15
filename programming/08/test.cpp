#include <stdio.h>
#include <time.h>

int data[1000000];
int stack[1000000];

int main(void)
{
	clock_t start, end;
	start = clock();

	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL)
		printf("파일 열기 실패");

	int t, n;
	fscanf(fp, "%d", &t);
	for (int i = 0; i < t; i++) {
		fscanf(fp, "%d", &n);
		int idx = 0, result = 0;
		for (int j = 0; j < n; j++) {
			bool min = true;
			fscanf(fp, "%d", &data[j]);
			for (int k = 0; k < idx; k++) {
				if (data[stack[k]] <= data[j]) {
					stack[k] = j;
					int tmp = idx;
					idx = k + 1;
					for (int l = idx; l < tmp; l++)
						stack[l] = 0;
					min = false;
					break;
				}
			}
			if (min)
				stack[idx++] = j;
			result += idx == 1 ? stack[idx - 1] : stack[idx - 1] - stack[idx - 2] - 1;
		}
		printf("%d\n", result);
	}

	end = clock();
	printf("time : %f\n", (float)(end - start) / CLOCKS_PER_SEC);

	return 0;
}