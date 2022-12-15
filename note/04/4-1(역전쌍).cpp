/* 1. 수열에서 큰 값이 작은 값보다 앞서 나오는 경우 두 값을 역전된(inverted) 쌍이라고 부른다. 예를 들어
수열 4, 2, 1, 1, 3에는 (4, 2), (4, 1), (4, 1), (4, 3), (2, 1), (2, 1)의 총 6개의 역전된 쌍이 있다. 수열을
입력으로 받아서 역전된 쌍의 개수를 카운트하여 출력하는 프로그램을 작성하라. 키보드로부터 먼저
정수의 개수 100개 이하 n을 입력받고, 이어서 n개의 정수를 입력 받는다. */

#include <stdio.h>
#define MAX 100

int main(void)
{
    int n;
    int data[MAX];
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
        scanf_s("%d", &data[i]);

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