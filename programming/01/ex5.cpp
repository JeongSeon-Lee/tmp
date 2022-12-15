/* 통과 완료 */
#include <stdio.h>

void bubblesort(int n, int num[]);

/* 정렬하고 중복확인하는 것이 더 효율적 */
int main(void)
{
    int n;
    int num[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &num[i]);

    bubblesort(n, num);

    // 1 2 3 3 3 4 4 5 5 7 8 9 9 
    // 자기 바로 앞과 비교해서 삭제
    int j = 0;  // 첫번째 애는 무조건 살아남으니까 0으로 해도 됨
    for (int i=0; i<n; i++) {
        if (i==0 || num[i] > num[i-1])  // survive, 이동, 살아남은 애들의 위치를 알고 있어야 이동 가능
            num[j++] = num[i];
    }

    printf("%d: ", j);
    for (int i = 0; i < j; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}

void bubblesort(int n, int num[])
{
    for (int i=n-1; i>0; i--) {
        for (int j = 0; j < i; j++) {
            if (num[j] > num[j + 1]) {
                int tmp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmp;
            }
        }
    }
}

void bubblesort(int ary[], int n)
{
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (ary[j] > ary[j + 1]) {
                int tmp = ary[j];
                ary[j] = ary[j + 1];
                ary[jj + 1] = tmp;
            }
        }
    }
}