#include <stdio.h>
#include <math.h>
#define MAX 100

int main(void)
{
	int n;
	int mat[MAX][MAX];

    double rowmean[MAX], rowstd[MAX], colmean[MAX], colstd[MAX];

	FILE* fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(fp, "%d", &mat[i][j]);
		}
	}
	fclose(fp);

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += mat[i][j];
        }
        rowmean[i] = (double)sum / n;
    }
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j <n; j++) {
            sum += (mat[i][j] - rowmean[i]) * (mat[i][j] - rowmean[i]);
        }
        sum /= n;   // sum은 아니지만 쓸 일이 없으니까
        rowstd[i] = sqrt(sum);
    }
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mat[i][j];
        }
        colmean[j] = (double)sum / n;
    }
    for (int j = 0; j < n; j++) {
        double sum = 0.0;
        for (int i = 0; i <n; i++) {
            sum += (mat[i][j] - colmean[j]) * (mat[i][j] - colmean[j]);
        }
        sum /= n;   // sum은 아니지만 쓸 일이 없으니까
        colstd[j] = sqrt(sum);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("%lf %lf\n", rowmean[i], rowstd[i]);
    }
    for (int j = 0; j < n; j++) {
        printf("%lf ", colmean[j]);
    }
    printf("\n");
    for (int j = 0; j < n; j++) {
        printf("%lf ", colstd[j]);
    }
    printf("\n");

    return 0;
}