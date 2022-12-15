/* 4. 먼저 입력될 정수의 개수 100이하 n을 입력받고, 이어서 n개의 정수를 받아 순서대로 배열에 저장한다. 
그런 다음 키보드로 부터 다시 하나의 정수 k를 입력받은 후 n개의 정수들 중에서 k에 가장 가까운, 즉
k와의 차이의 절대값이 가장 작은 정수를 찾아 출력하는 프로그램을 작성하라. */

#include <stdio.h>

int abs(int a)
{
    if (a >= 0) return a;
    return -a;
}

int main(void)
{
    int n, k;
    int num[100];
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
        scanf_s("%d", &num[i]);
    scanf_s("%d", &k);

    /* 합, 최소값 등등등 다 비슷한 문제, 데이터를 다 읽고 답을 갱신해나가면 되는지 */
    /* 최소차이 */

    int idx_min_diff = 0;
    for (int i = 1; i < n; i++) {
        if (abs(num[i] - k) < abs(num[idx_min_diff] - k))
            idx_min_diff = i;
    }

    printf("%d", num[idx_min_diff]);

    return 0;
}