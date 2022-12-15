/* 통과 완료 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char * words[100000];
    int counter[100000] = { 0 };   // 컴파일러가 일반적으로 해주지만, 0으로 초기화하는 것이 좋음
    int n = 0;
    char buf[40];
    FILE *fp = fopen("02/harry.txt", "r");
    while (fscanf(fp, "%s", buf) != EOF) {
        if (strlen(buf) < 6)
            continue;
        /* 중복 제거와 삽입정렬 */
        bool duplicate = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(buf, words[i]) == 0)
                duplicate = true;
                counter[i]++;
                break;
        }
        if (!duplicate) {
            int j = n - 1;
            while(j >= 0 && strcmp(buf, words[j]) < 0) {
                words[j + 1] = words[j];
                counter[j + 1] = counter[j];
                j--;
            }
            words[j + 1] = strdup(buf);
            counter[j + 1] = 1;
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