#include <stdio.h>
#include <ctype.h>

int read_line_with_compression(char compressed[], int limit);

int main(void)
{
    char line[80];
    while (1) {
        printf("$ ");
        int length = read_line_with_compression(line, 80);
        printf("%s:%d\n", line, length);
    }
}

int read_line_with_compression(char compressed[], int limit)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < limit - 1 && (!isspace(ch) || i > 0 && !isspace(compressed[i - 1])))
            /* 공백이 아닌 문자일 시 넣고,
            맨 앞 요소는 직전 문자가 없으니 해당 사항 없음, 
            그리고 맨 앞 요소가 아니면서 동시에 직전문자가 공백이 아닐 시에 넣음 */
            compressed[i++] = ch;
    }
    if (i > 0 && isspace(compressed[i - 1]))    // 문자가 엔터만 들어왔을 경우 개수 0을 반환해야 함
        i--;    // 개행을 만나 while을 빠져나왔고 직전이 공백일 시 한 칸 땡김
    compressed[i] = '\0';
    return i;
}