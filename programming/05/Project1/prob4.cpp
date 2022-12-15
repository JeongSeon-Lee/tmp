/* 통과 완료 */
#include <stdio.h>

int main(void)
{
	char tag;
	FILE* fp = 0;
	fopen_s(&fp, "sample.html", "r");
	FILE* op = 0;
	fopen_s(&op, "sample.txt", "w");
	while (fscanf_s(fp, "%c", &tag) != EOF) {
		if (tag == '<') {
			while (tag != '>')
				fscanf_s(fp, "%c", &tag);
		}
		else {
			fprintf(op, "%c", tag);
		}
	}
	fclose(fp);
	fclose(op);
	return 0;
}