#include <stdio.h>
#include <string.h>

void bubblesort(int n, char* words[], char* meanings[]);

int main(void)
{
	char* words[100000];
	char* meanings[100000];
	FILE* fp = NULL;
	fopen_s(&fp, "shuffled_dict.txt", "r");
	char buf[1000];
	int n = 0;
	while (fscanf_s(fp, "%s", buf, sizeof(buf)) != EOF) {	
		words[n] = _strdup(buf);
		fgets(buf, 1000, fp);
		meanings[n] = _strdup(buf);
		n++;
	}
	fclose(fp);

	bubblesort(n, words, meanings);
	fopen_s(&fp, "sorted_dict.txt", "w");
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%s\t%s", words[i], meanings[i]);
	}
	fclose(fp);

	return 0;
}

void bubblesort(int n, char* words[], char* meanings[]) {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strcmp(words[j], words[j + 1]) > 0) {
				char* tmp = words[j];
				words[j] = words[j + 1];
				words[j + 1] = tmp;
				tmp = meanings[j];
				meanings[j] = meanings[j + 1];
				meanings[j + 1] = tmp;
			}
		}
	}
}