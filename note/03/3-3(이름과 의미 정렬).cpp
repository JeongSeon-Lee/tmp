/* 3. ���� ���� shuffled_dict.txt�� �д´�. �� ���Ͽ��� �� �ٸ��� �ϳ��� ���ܾ�� �� �ܾ ���� ����
���� ����Ǿ� �ִ�. ���ܾ�� �� �ܾ ���� �������� �ϳ��� �� ����(��\t��)�� ���еǾ� �ִ�. ����
��� �ϳ��� ���� �ҹ��� ���ڿ��̸�, �������� ���� ���� �ܾ�� ������ �����̴�. �� ���� ���Ͽ��� 
�ܾ���� ������ ������ ���ĵǾ� ���� �ʴ�. �� ������ ���� �� �ܾ���� ������ ������ �����Ͽ� 
��sorted_dict.txt����� �̸��� ���ο� ������ �����Ͽ� �����ϴ� ���α׷��� �ۼ��϶�. ����� ��
�Ͽ����� �� �ٿ� �ϳ��� �ܾ�� �� �ܾ ���� ������ �� ���ڷ� �����Ͽ� �����ؾ� �Ѵ�. �Ʒ��� ��
�ٸ� ��� ������ ���۰� �� �κ��� �����ش�. */

#include <stdio.h>
#include <string.h>
#define LINE_LENGTH 1000
#define MAX 10000

char* words[MAX];
char* exp[MAX];

int main(void)
{
    char* words[100000];
    char* exp[100000];
    char* context;
    FILE* fp = NULL;
    fopen_s(&fp, "shuffled_dict.txt", "r");
    char line[LINE_LENGTH];
    int n = 0;
    while (fgets(line, LINE_LENGTH, fp) != NULL) {
        // �������� �������� �ִٸ� ������ ������ �������� �ʴ´�.// hello\n\0
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';
            // ������ ���๮�ڰ� ���� �� ���� �ϳ��� �Ҿ����
        // ������ ������ �Ǿ����� �� �װ͵� ����, �ٵ� �̰� ���� ������ �����ٰ� �ٽ� ���ڰ� ������ ��찡 �Ϲ����̴� �ڿ������� ���̳�. ���� ���� �˰��򿡼��� ���ľ���
        if (strlen(line) <= 0)
            continue;

        // tokenizing
        char* p = strtok_s(line, "\t", &context);

        // insertion sort
        // �ٷιٷ� �����ϸ� ����
        int j = n - 1;
        while (j >= 0 && strcmp(words[j], p) > 0) {
            words[j + 1] = words[j];
            exp[j + 1] = exp[j];
            j--;
        }
        words[j + 1] = _strdup(p);
        p = strtok_s(NULL, "\t", &context);
        exp[j + 1] = _strdup(p);
        n++;
    }
    fclose(fp);

    fopen_s(&fp, "sorted_dict.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s\t%s", words[i], exp[i]);
        fprintf(fp, "\n");
    }
    fclose(fp);

    return 0;
}