/* 2. �Է����� �ϳ��� n*n ����� ����� ���� input.txt�� �־�����. ������ ù �ٿ��� ����� ũ�� 10���� n
�� ����Ǿ� �ְ�, �̾��� n�ٿ��� �� �ٸ��� n���� ������ ����Ǿ� �ִ�. �� ������ �о
�� ���� ��հ� ǥ������, �� ���� ��հ� ǥ�������� ���ؼ� �Ʒ��� ���� ���� �������� ȭ������ ��
���ϴ� ���α׷��� �ۼ��϶�. ��հ� ǥ�������� �Ҽ��� ���� 2�ڸ����� ����Ѵ�. �������� ��� ��
���� �Ʒ��� ���� ������. ����� ǥ�������� ������ ���� ���ǵȴ�. ��Ʈ(square root)�� ����ϱ� ��
�ؼ� math.h�� include�ϰ� sqrt�Լ��� ����϶�. */

#include <stdio.h>
#include <math.h>
#define MAX 100

int main(void)
{
    int n;
    int mat[MAX][MAX];

    double rowmean[MAX], rowstd[MAX], colmean[MAX], colstd[MAX];

    FILE* fp = 0;
    fopen_s(&fp, "input.txt", "r");
    fscanf_s(fp, "%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf_s(fp, "%d", &mat[i][j]);
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
        for (int j = 0; j < n; j++) {
            sum += (mat[i][j] - rowmean[i]) * (mat[i][j] - rowmean[i]);
        }
        sum /= n;
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
        for (int i = 0; i < n; i++) {
            sum += (mat[i][j] - colmean[j]) * (mat[i][j] - colmean[j]);
        }
        sum /= n;
        colstd[j] = sqrt(sum);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("%.2lf %.2lf\n", rowmean[i], rowstd[i]);
    }
    for (int j = 0; j < n; j++) {
        printf("%.2lf ", colmean[j]);
    }
    printf("\n");
    for (int j = 0; j < n; j++) {
        printf("%.2lf ", colstd[j]);
    }
    printf("\n");

    return 0;
}