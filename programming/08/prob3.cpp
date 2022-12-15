/* 통과 완료 */
#include <stdio.h>
#include <time.h>

int data[1000000];
int stack[1000000];

int main(void)
{
	clock_t start, end;
	start = clock();

	FILE* fp = 0;
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL)
		printf("파일 열기 실패");

	int t, n;
	fscanf_s(fp, "%d", &t);
	for (int i = 0; i < t; i++) {
		fscanf_s(fp, "%d", &n);
		int idx = 0;
		unsigned long long result = 0;
		for (int j = 0; j < n; j++) {
			bool min = true;
			fscanf_s(fp, "%d", &data[j]);
			for (int k = 0; k < idx; k++) {
				if (data[stack[k]] <= data[j]) {
					stack[k] = j;
					int tmp = idx;
					idx = k + 1;
					min = false;
					break;
				}
			}
			if (min)
				stack[idx++] = j;
			result += idx == 1 ? stack[idx - 1] : (stack[idx - 1] - stack[idx - 2] - 1);
		}
		printf("%d\n", result % 1000000);

	}
	fclose(fp);

	end = clock();
	printf("Elapsed Time : %f\n", (float)(end - start) / CLOCKS_PER_SEC);

	return 0;
}