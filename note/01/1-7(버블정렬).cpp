/* 7. 입력으로 100미만 n개의 영문 문자열을 받는다. 각 문자열의 길이는 20이하이다. 이 문자열들을 문자열
의 길이가 짧은 것에서 부터 긴 것 순서로 정렬하여 출력하라. 단, 길이가 동일한 문자열들은 그들 끼리
사전식 순서로 정렬되어야 한다. 입력 형식은 먼저 문자열의 개수 n이 주어지고, 이어서 n개의 문자열
이 한 줄에 하나씩 주어진다. 문자열을 입력받아 배열에 저장하는 일은 main 함수에서 하고, 정렬하는
일은 별개의 함수를 만들어서 호출하라. 그런 다음 출력하는 일은 다시 main함수로 돌아와서 한다. */

#include <stdio.h>
#include <string.h>

void bubblesort(int n, char* words[]);

int main(void)
{
    char* words[100];
    int n = 0;
    char buf[20];

    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf_s("%s", buf, 20);
        words[i] = _strdup(buf);
    }

    bubblesort(n, words);

    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}

void bubblesort(int n, char* words[])
{
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])
                || (strlen(words[j]) == strlen(words[j + 1])
                    && strcmp(words[j], words[j + 1]) > 0)) {
                char* tmp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = tmp;
            }
        }
    }
}