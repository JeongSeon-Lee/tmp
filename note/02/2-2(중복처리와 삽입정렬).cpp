/* 2. 입력으로 텍스트 파일 harry.txt를 읽어서 이 파일에 등장하는 모든 단어의 목록을 중복된 단어없
이 사전식 순서로 정렬하여 강의 슬라이드 16페이지와 같은 자료구조로 저장한다. 이제 새로운 단어 하
나를 키보드로부터 입력받는다. 저장된 단어들 중에 이 새로운 단어를 접두어(prefix)로 하는 모든 단어
를 찾아서 한 줄에 하나씩 출력하는 프로그램을 작성하라. 마지막으로 찾아진 단어의 개수를 출력하라.
어떤 단어가 다른 단어의 접두어인지는 표준 라이브러리가 제공하는 strncmp 함수를 이용하여 검사
할 수 있다. 이 함수의 사용 방법은 검색하여 알아보라. */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char* words[100000];
    int n = 0;
    char buf[40];
    FILE* fp = 0;
    fopen_s(&fp, "harry.txt", "r");
    while (fscanf_s(fp, "%s", buf, 40) != EOF) {
        bool duplicate = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(buf, words[i]) == 0) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            int j = n - 1;
            while (j >= 0 && strcmp(buf, words[j]) < 0) {
                words[j + 1] = words[j];
                j--;
            }
            words[j + 1] = _strdup(buf);
            n++;
        }
    }
    fclose(fp);

    char prefix[40];
    scanf_s("%s", prefix, 40);
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