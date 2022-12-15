/* 3. 다음과 같은 형식의 입력 파일 table.txt를 읽어서 아래의 예와 같이 output.txt파일에 테이블 형태
로 출력하는 프로그램을 작성하라. 입력 파일의 첫 줄에는 테이블의 행의 개수 10이하 m과 열의 개수
10이하 n이 주어진다. 이어진 m줄에는 각 줄 마다 테이블의 한 행에 들어갈 n개의 내용이 문자 &로 구분
되어 주어진다. 테이블의 어떤 칸은 빈 칸일 수도 있다는 것을 유념하라. 빈 칸인 경우에도 하나 이상의
공백 문자로 표현되어 있다. 불필요한 공백 문자들을 제거하여 최대한 깔끔하게 출력되도록 하라. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 200

void compress(char* str);

int main(void)
{
    int m, n;
    char* table[10][10];
    char line[MAX];
    char* context;
    FILE* fp = 0;
    fopen_s(&fp, "table.txt", "r");
    fscanf_s(fp, "%d%d ", &m, &n);
    // 공백을 뒤에 두면 화이트스페이스까지 읽음
    for (int i = 0; i < m; i++) {
        fgets(line, MAX, fp);
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0'; 
        // 마지막에는 뉴라인 캐릭터가 없으니까 한 문자가 사라짐
        // printf("%s\n", line);   // 4 4뒤 뉴 라인 캐릭터 읽음

        char* p = strtok_s(line, "&", &context);
        table[i][0] = _strdup(p);
        for (int j = 1; j < n; j++) {
            p = strtok_s(NULL, "&", &context);
            table[i][j] = _strdup(p);
        }
    }

    fclose(fp);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            compress(table[i][j]);
        }
    }

    int colwidth[10] = { 0 };
    for (int j = 0; j < n; j++) {
        colwidth[j] = strlen(table[0][j]);
        for (int i = 1; i < m; i++) {
            if (strlen(table[i][j]) > colwidth[j])
                colwidth[j] = strlen(table[i][j]);
        }
    }

    FILE* of = 0;
    fopen_s(&of, "output.txt", "w");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(of, "%s", table[i][j]);
            for (int k = 0; k <= colwidth[j] - strlen(table[i][j]); k++) {
                fprintf(of, " ");
            }
        }
        fprintf(of, "\n");
    }
    fclose(of);

    return 0;
}

void compress(char* str) {
    int s = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (!isspace(str[i]) ||
            i > 0 && !isspace(str[i - 1])) 
            /* 화이트스페이스이지만 살아남아야 한다면 */ // if str[i] should survive
            str[s++] = str[i];
    }
    if (s > 0 && isspace(str[s - 1]))
        str[s - 1] = '\0';
    else
        str[s] = '\0';
}