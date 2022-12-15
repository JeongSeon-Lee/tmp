#include <stdio.h>
#define MAX 100

int main(void)
{
    int n;
    int data[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (data[i] > data[j])
                count++;
        }
    }

    printf("%d\n", count);

    return 0;
}