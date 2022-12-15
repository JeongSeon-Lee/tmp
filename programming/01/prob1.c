/* 통과 완료 */
#include <stdio.h>

int main(void)
{
    int value;

    scanf("%d", &value);

    do {
        value /= 2;
        printf("%d ", value);
    } while (value != 0);

    return 0;
}