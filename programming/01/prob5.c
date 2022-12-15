/* 통과 완료 */
#include <stdio.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void ascending(int a[], int count)
{
    int i, j;
    for(i = 0; i < count - 1; i++) {
        for (j = count - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(int, a[j - 1], a[j]);
    }
}

int main(void)
{
    int n, input, ary[99];
    int i, j, count = 0;
    
    scanf("%d", &n);
    scanf("%d", &input);
    ary[0] = input;

    for (j = 0; j < n - 1; j++) {
        scanf("%d", &input);
        count++;
        for (i = 0; i < count; i++) {
            if (ary[i] == input) {
                count--;
                break;
            }
            if (i == count - 1)
                ary[count] = input;
        }
    }

    count++;

    ascending(ary, count);

    printf("%d: ", count);
    for (i = 0; i < count; i++) {
        printf("%d ", ary[i]);
    }

    return 0;
}