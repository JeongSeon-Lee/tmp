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
    
    scanf("%d", &input);
    ary[0] = input;
    printf("%d\n", ary[0]);

    while (1) {
        scanf("%d", &input);
        if (input == -1)
            break;
        count++;
        for (i = 0; i < count; i++) {
            if (ary[i] == input) {
                count--;
                printf("duplicate\n");
                break;
            }
            if (i == count - 1) {
                ary[count] = input;
                ascending(ary, count + 1);
                for (i = 0; i < count + 1; i++)
                    printf("%d ", ary[i]);
                printf("\n");
            }     
        }
    }

    return 0;
}