/* 통과 완료 */
#include <stdio.h>
#include <string.h>

void sort(char a[][21], int n)
{
    int i, j, k;
    char tmp[21];
    int len[99];

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (strcmp(a[j - 1], a[j]) > 0) {
                strcpy(tmp, a[j - 1]);
                strcpy(a[j - 1], a[j]);
                strcpy(a[j], tmp);
            }
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (strlen(a[j - 1]) > strlen(a[j])) {
                strcpy(tmp, a[j - 1]);
                strcpy(a[j - 1], a[j]);
                strcpy(a[j], tmp);
            }
        }
    }
}

int main(void)
{
    int n, i, j;
    char ary[99][21];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", &ary[i]);
    }

    sort(ary, n);

    for (i = 0; i < n; i++) {
        printf("%s\n", ary[i]);
    }

    return 0;
}