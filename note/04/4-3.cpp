/* 3. ������ ���� ������ �Է� ���� table.txt�� �о �Ʒ��� ���� ���� output.txt���Ͽ� ���̺� ����
�� ����ϴ� ���α׷��� �ۼ��϶�. �Է� ������ ù �ٿ��� ���̺��� ���� ���� 10���� m�� ���� ����
10���� n�� �־�����. �̾��� m�ٿ��� �� �� ���� ���̺��� �� �࿡ �� n���� ������ ���� &�� ����
�Ǿ� �־�����. ���̺��� � ĭ�� �� ĭ�� ���� �ִٴ� ���� �����϶�. �� ĭ�� ��쿡�� �ϳ� �̻���
���� ���ڷ� ǥ���Ǿ� �ִ�. ���ʿ��� ���� ���ڵ��� �����Ͽ� �ִ��� ����ϰ� ��µǵ��� �϶�. */

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
    // ������ �ڿ� �θ� ȭ��Ʈ�����̽����� ����
    for (int i = 0; i < m; i++) {
        fgets(line, MAX, fp);
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0'; 
        // ���������� ������ ĳ���Ͱ� �����ϱ� �� ���ڰ� �����
        // printf("%s\n", line);   // 4 4�� �� ���� ĳ���� ����

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
            /* ȭ��Ʈ�����̽������� ��Ƴ��ƾ� �Ѵٸ� */ // if str[i] should survive
            str[s++] = str[i];
    }
    if (s > 0 && isspace(str[s - 1]))
        str[s - 1] = '\0';
    else
        str[s] = '\0';
}