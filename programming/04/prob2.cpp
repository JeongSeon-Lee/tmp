/* 통과 완료 */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int n;
	int num[100][100];
	int i, j;
	double ave = 0.0, dev = 0.0;
	FILE* fp = 0;
	fopen_s(&fp, "input.txt", "r");
	fscanf_s(fp, "%d", &n);
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf_s(fp, "%d", &num[i][j]);
		}
	}
	fclose(fp);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", num[i][j]);
			ave += num[i][j];
		}
		ave /= n;
		printf("%.2lf ", ave);
		for (j = 0; j < n; j++) {
			dev += (num[i][j] - ave) * (num[i][j] - ave);
		}
		dev /= n;
		dev = sqrt(dev);
		printf("%.2lf\n", dev);
		ave = 0.0;
		dev = 0.0;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			ave += num[j][i];
		}
		ave /= n;
		printf("%.2lf ", ave);
		ave = 0.0;
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			ave += num[j][i];
		}
		ave /= n;
		for (j = 0; j < n; j++) {
			dev += (num[j][i] - ave) * (num[j][i] - ave);
		}
		dev /= n;
		dev = sqrt(dev);
		printf("%.2lf ", dev);
		dev = 0.0;
	}
	return 0;
}