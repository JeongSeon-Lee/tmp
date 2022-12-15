#include <stdio.h>
#include <string.h>

bool jaum(char c)
{
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c = 'u');
}

int main(void)
{
    char str[100];
    scanf("%s", str);
    int len = 0;
    int max_len = 0;
    int max_pos = -1; // 애초에 유효하지 않은 값
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