/* 통과 완료 */
#include <stdio.h>
#include <string.h>

void bubblesort(int n, char *words[]);

int main(void)
{
    char * words[100000];
    char word[30];
    FILE *fp = fopen("02/harry.txt", "r");
    if (fp == NULL) {
        puts("파일 열기 실패");
        return 1;
    }
    int tmp_count = 0;
    while (fscanf(fp, "%s", word) != EOF) {
        if (strlen(word) >= 6)
            words[tmp_count++] = strdup(word);
    }
    fclose(fp);

    bubblesort(tmp_count, words);
    int count = 0;
    int num[2000];
    for (int i = 0; i < tmp_count; i++) {
        if (i == 0 || strcmp(words[i], words[i - 1]) > 0) {
            strcpy(words[count], words[i]);
            num[count++] = 1;
        }
        else
            num[count - 1]++;
    }

    for (int i = 0; i < count; i++) {
        printf("%s: ", words[i]);
        printf("%d\n", num[i]);
    }
    printf("%d", count);

    return 0;
}

void bubblesort(int n, char *words[])
{
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char *tmp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = tmp;
            }
        }
    }
}