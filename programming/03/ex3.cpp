#include <stdio.h>
#include <string.h>
#define LINE_LENGTH 1000
#define MAX 10000

char *words[MAX];
char *exp[MAX];

int main(void)
{
	char* words[100000];
	char* meanings[100000];
	FILE* fp = NULL;
	fopen_s(&fp, "shuffled_dict.txt", "r");
	char line[LINE_LENGTH];
	int n = 0;
    while (fgets(line, LINE_LENGTH, fp) != NULL) { // 마지막에 뉴라인이 있다면 파일의 끝으로 생각하지 않는다.// hello\n\0
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0'; // 마지막 개행문자가 없을 시 문자 하나를 잃어버림
        // 개행이 여러번 되어있을 시 그것도 읽음, 근데 이건 많은 개행이 나오다가 다시 문자가 나오는 경우가 일반적이니 자연스러운 것이나. 현재 문제 알고리즘에서는 고쳐야함
        if (strlen(line) <= 0)
            continue;

        // tokenizing
        char *p = strtok(line, "\t"/* 문자열 겹따옴표*/);

        // insertion sort
        // 바로바로 정렬하면 좋음
        int j = n - 1;
        while (j >= 0 && strcmp(words[j], words[j + 1]) > 0) {
            words[j + 1] = words[j];
            exp[j + 1] = exp[j];
            j--;
        }
        words[j + 1] = strdup(p);
        p = strtok(NULL, "\t");
        exp[j + 1] = strdup(p);
        n++;
    }
	fclose(fp);

	fopen_s(&fp, "sorted_dict.txt", "w");
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%s\t%s", words[i], meanings[i]);
	}
	fclose(fp);

	return 0;
}