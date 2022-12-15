/* 3. 사전 파일 shuffled_dict.txt을 읽는다. 이 파일에는 각 줄마다 하나의 “단어”와 그 단어에 대한 “설
명”이 저장되어 있다. “단어”와 그 단어에 대한 “설명”은 하나의 탭 문자(‘\t’)로 구분되어 있다. “단
어”는 하나의 영문 소문자 문자열이며, “설명”은 여러 개의 단어로 구성된 문장이다. 이 사전 파일에서 
단어들은 사전식 순서로 정렬되어 있지 않다. 이 파일을 읽은 후 단어들을 사전식 순서로 정렬하여 
“sorted_dict.txt”라는 이름의 새로운 파일을 생성하여 저장하는 프로그램을 작성하라. 저장된 파
일에서는 한 줄에 하나의 단어와 그 단어에 대한 설명을 탭 문자로 구분하여 저장해야 한다. 아래는 올
바른 출력 파일의 시작과 끝 부분을 보여준다. */

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
        // 마지막에 뉴라인이 있다면 파일의 끝으로 생각하지 않는다.// hello\n\0
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';
            // 마지막 개행문자가 없을 시 문자 하나를 잃어버림
        // 개행이 여러번 되어있을 시 그것도 읽음, 근데 이건 많은 개행이 나오다가 다시 문자가 나오는 경우가 일반적이니 자연스러운 것이나. 현재 문제 알고리즘에서는 고쳐야함
        if (strlen(line) <= 0)
            continue;

        // tokenizing
        char* p = strtok_s(line, "\t", &context);

        // insertion sort
        // 바로바로 정렬하면 좋음
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