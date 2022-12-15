/* 통과 완료 */
#include <stdio.h>

int abs(int a)
{
    if (a>=0) return a;
    return -a;
}

int main(void)
{
    int n, k;
    int num[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &num[i]);
    scanf("%d", &k);

    /* 합, 최소값 등등등 다 비슷한 문제, 데이터를 다 읽고 답을 갱신해나가면 되는지 */
    /* 최소차이 */

    int idx_min_diff = 0;
    for (int i=1; i<n; i++) {
        if (abs(num[i]-k) < abs(num[idx_min_diff]-k))
            idx_min_diff = i;
    }

    printf("%d", num[idx_min_diff]);

    return 0;
}