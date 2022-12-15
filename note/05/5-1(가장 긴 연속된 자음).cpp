/* 1. 하나의 영문 소문자로 된 문자열이 입력으로 주어진다. 이 문자열에서 자음이 가장 여러 번 연속해서
등장하는 부분을 찾아서 그 부분을 출력하는 프로그램을 작성하라. 예를 들어 문자열 “nietzsche”에
서는 “tzsch”가 가장 긴 연속된 자음이다. 입력 문자열의 길이는 100이하이고, ‘a’, ‘e’, ‘i’, 
‘o’, ‘u’를 제외한 모든 알파벳은 자음으로 간주한다. */

#include <stdio.h>
#include <string.h>

bool jaum(char c)
{
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void)
{
    char str[100];
    scanf_s("%s", str, 100);
    int len = 0;
    int max_len = 0;
    int max_pos = -1;
    // 애초에 유효하지 않은 값

    // eetghaaabbstruuugdjsadgjaasdg
    // 00123000123450001234012300123

    for (int i = 0; i < strlen(str); i++) {
        if (!jaum(str[i]))
            len = 0;
        else {
            len++;
            if (len > max_len) {
                max_len = len;
                max_pos = i;
            }
        }
    }

    for (int i = 0; i < max_len; i++) {
        printf("%c", str[max_pos - max_len + 1 + i]);
    }
    printf("\n");
}