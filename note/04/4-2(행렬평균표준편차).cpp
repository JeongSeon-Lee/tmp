/* 2. 입력으로 하나의 n*n 행렬이 저장된 파일 input.txt가 주어진다. 파일의 첫 줄에는 행렬의 크기 10이하 n
이 저장되어 있고, 이어진 n줄에는 각 줄마다 n개의 정수가 저장되어 있다. 이 파일을 읽어서
각 행의 평균과 표준편차, 각 열의 평균과 표준편차를 구해서 아래의 예와 같은 형식으로 화면으로 출
력하는 프로그램을 작성하라. 평균과 표준편차는 소수점 이하 2자리까지 출력한다. 세부적인 출력 형
식은 아래의 예를 따른다. 참고로 표준편차는 다음과 같이 정의된다. 루트(square root)를 계산하기 위
해서 math.h를 include하고 sqrt함수를 사용하라. */

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