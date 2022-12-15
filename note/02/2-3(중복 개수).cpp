/* 3. 입력으로 텍스트 파일 harry.txt를 읽는다. 이 텍스트 파일은 오직 영문 소문자만으로 구성되어 있
다. 이 파일에 등장하는 길이가 6이상인 모든 단어의 목록과 각 단어의 등장 빈도를 구하여 화면으로 출
력하는 프로그램을 작성하라. 단어들은 사전식 순서로 정렬되어 출력되어야 한다. 출력 파일의 각 줄에
하나의 단어와 그 단어의 등장 빈도를 콜론(:)으로 구분하여 출력하라. 동일한 단어가 중복해서 출력되
어서는 안된다. 단어들은 강의 슬라이드 16페이지와 같은 자료구조로 저장되어야 한다. 출력의 마지막
에는 전체 단어의 개수를 출력하라. 아래는 올바른 출력의 시작 부분과 끝 부분을 보여준다. */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char* words[100000];
    int counter[100000] = { 0 };   // 컴파일러가 일반적으로 해주지만, 0으로 초기화하는 것이 좋음
    int n = 0;
    char buf[40];
    FILE* fp = 0;
    fopen_s(&fp, "harry.txt", "r");
    while (fscanf_s(fp, "%s", buf, 40) != EOF) {
        if (strlen(buf) < 6)
            continue;
        /* 중복 제거와 삽입정렬 */
        bool duplicate = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(buf, words[i]) == 0) {
                duplicate = true;
                counter[i]++;
                break;
            }
        }
        if (!duplicate) {
            int j = n - 1;
            while (j >= 0 && strcmp(buf, words[j]) < 0) {
                words[j + 1] = words[j];
                counter[j + 1] = counter[j];
                j--;
            }
            words[j + 1] = _strdup(buf);
            counter[j + 1] = 1;
            n++;
        }
    }
    fclose(fp);
 
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i], counter[i]);
    }
    printf("%d", n);


    return 0;
}