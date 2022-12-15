#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("tinput.txt", "r");
    int n, plusOne = 0, test;
    fscanf(fp, "%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        plusOne +=1;
        fscanf(fp, "%d", &test);
        if (plusOne != test) {
            printf("%d: %d != %d\n", i, plusOne, test);
            break;
        }
    }
    if (i == n)
        printf("¼º°ø\n");

    fclose(fp);
    return 0;
}