#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 200

void compress(char *str);

int main(void)
{
    int m, n;
    char * table[10][10];
    char line[MAX];
    FILE *fp = fopen("04/table.txt", "r");
    fscanf(fp, "%d%d ", &m, &n); // 공백을 뒤에 두면 화이트스페이스까지 읽음
    for (int i = 0; i < m; i++) {
        fgets(line, MAX, fp);
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';  // 마지막에는 뉴라인 캐릭터가 없으니까 한 문자가 사라짐
        // printf("%s\n", line);   // 4 4뒤 뉴 라인 캐릭터 읽음

        char *p = strtok(line, "&");
        table[i][0] = strdup(p);
        for (int j = 1; j < n; j++) {
            p = strtok(NULL, "&");
            table[i][j] = strdup(p);
        }
    }

    fclose(fp);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            compress(table[i][j]);
        }
    }

    int colwidth[10] { 0 };
    for (int j = 0; j < n; j++) {
        colwidth[j] = strlen(table[0][j]);
        for (int i = 1; i < m; i++) {
            if (strlen(table[i][j]) > colwidth[j])
                colwidth[j] = strlen(table[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%s(%d):", table[i][j], strlen(table[i][j]));
        }
        printf("\n");
    }
    printf("\n");

    FILE *of = fopen("04/output.txt", "w");
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

void compress(char *str) {
    int s = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (!isspace(str[i]) ||
                i >0 && !isspace(str[i - 1]) /* 화이트스페이스이지만 살아남아야 한다면 */) // if str[i] should survive
            str[s++] = str[i];
    }
    if (s > 0 && isspace(str[s - 1]))
        str[s - 1] = '\0';
    else
        str[s] = '\0';
}