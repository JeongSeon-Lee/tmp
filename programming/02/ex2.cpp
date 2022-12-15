/* 통과 완료 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char * words[100000];
    int n = 0;
    char buf[40];
    FILE *fp = fopen("02/harry.txt", "r");
    while (fscanf(fp, "%s", buf) != EOF) {
        /* 중복 제거와 삽입정렬 */
        bool duplicate = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(buf, words[i]) == 0)
                duplicate = true;
                break;
        }
        if (!duplicate) {
            int j = n - 1;
            while(j >= 0 && strcmp(buf, words[j]) < 0) {
                words[j + 1] = words[j];
                j--;
            }
            words[j + 1] = strdup(buf);
            n++;
        }
    }
    fclose(fp);     // 미리 타이핑 해놓고

    char prefix[40];
    scanf("%s", prefix);
    int pref_count = 0;
    for (int i = 0; i < n; i++) {
        if (strncmp(prefix, words[i], strlen(prefix)) == 0) {
            printf("%s\n", words[i]);
            pref_count++;
        }
    }
    printf("%d\n", pref_count);

    return 0;
}