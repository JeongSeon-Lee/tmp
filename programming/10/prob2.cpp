/* 통과 완료 */
#include <stdio.h>
#include <string.h>

int compare(char* str1, char* str2) {
	if (*str1 == '\0' && *str2 == '\0')
		return 0;
	if (str1[0] == str2[0])
		return compare(str1 + 1, str2 + 1);
	else if (str1[0] < str2[0])
		return -1;
	else
		return 1;
}

int main(void) {
	char str1[100], str2[100];
	scanf_s("%s%s", str1, 100, str2, 100);
	if (compare(str1, str2) <= 0)
		printf("%s\n%s\n", str1, str2);
	else {
		char* tmp = str1;
		strcpy_s(str1, str2);
		strcpy_s(str2, tmp);
		
	}
	return 0;
}