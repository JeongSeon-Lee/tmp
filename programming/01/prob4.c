/* 통과 완료 */
#include <stdio.h>

int main(void)
{
    int n, value;
    int ary1[100], ary2[100];
    int i, min;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ary1[i]);
    }
    scanf("%d", &value);

    for (i = 0; i < n; i++) {
        int temp = value - ary1[i];
        if (temp < 0)
            ary2[i] = -temp;
        else ary2[i] = temp;
    }

    min = ary2[0];
    for (i = 1; i < n; i++) {
        if (min > ary2[i])
            min = ary2[i];
    }

    for (i = 0; i < n; i++) {
        if (min == ary2[i])
            break;
    }

    printf("%d", ary1[i]);

    return 0;
}