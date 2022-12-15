/* 5. 사용자로부터 100개 미만 n개의 정수를 입력받아 크기순으로 정렬한 후 중복된 수를 제거하는 프로그램을
작성하라. 입력 형식은 먼저 n의 값이 주어지고 이어서 개의 정수들이 주어진다. 예를 들어 n = 8이고
입력된 정수들이 4, 7, 4, 12, 4, 10, 9, 7 이라면 중복을 제거하고 남은 정수들은 4, 7, 9, 10, 12 이다. 
그러면 먼저 남은 정수의 개수 5를 출력하고 콜론(:)을 출력한 후 남은 정수들을 오름차순으로 출력한
다.*/

#include <stdio.h>

void bubblesort(int n, int num[]);

/* 정렬하고 중복확인하는 것이 더 효율적 */
int main(void)
{
    int n;
    int num[100];
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
        scanf_s("%d", &num[i]);

    bubblesort(n, num);

    // 1 2 3 3 3 4 4 5 5 7 8 9 9 
    // 자기 바로 앞과 비교해서 삭제
    int j = 0;
    // 첫번째 애는 무조건 살아남으니까 0으로 해도 됨
    for (int i = 0; i < n; i++) {
        if (i == 0 || num[i] > num[i - 1])
            // survive, 이동, 살아남은 애들의 위치를 알고 있어야 이동 가능
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
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (num[j] > num[j + 1]) {
                int tmp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmp;
            }
        }
    }
}