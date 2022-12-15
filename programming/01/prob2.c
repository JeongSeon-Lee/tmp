/* 통과 완료 */
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void ascending(int a[], int n);

int main(void)
{
    int n;
    int *ary;
    int i;

    scanf("%d", &n);
    ary = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
    }

    ascending(ary, n);
    printf("%d ", ary[0]);
    printf("%d", ary[1]);

    free(ary);
    return 0;
}

void ascending(int a[], int n)
{
    int i, j;
    for(i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(int, a[j - 1], a[j]);
    }
}