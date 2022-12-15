#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 100

int read_line(char str[], int limit);

int main(void)
{
    char buffer[BUFFER_SIZE];
    int k;
    while (1) {
        printf("$ ");
        // gets(buffer);    gets는 온전히 user input에 관련한 함수이므로 버퍼 오버플로우에 굉장히 취약
        /* fgets(buffer, BUFFER_SIZE, stdin);    
        문제1 : '\n'을 버퍼에 저장하고 길이에 포함 됨
        해결 방법 : buffer[strlen(buffer) - 1] = '\0';
        문제 2 : 버퍼사이즈를 초과할 시 완전히 무시가 안 됨*/
        k = read_line(buffer, BUFFER_SIZE);
        printf("%s:%d\n", buffer, /* strlen(buffer) */ k);
    }
    return 0;
}

int read_line(char str[], int limit)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')    // getchar()로 입력받고 한 문자씩 검사
        if (i < limit - 1)              // 입력받은 문자열이 버퍼사이즈를 초과하지 않는 선에서
            str[i++] = ch;              // 하나하나씩 배열에 넣음
    str[i] = '\0';
    return i;
}