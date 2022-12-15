/* 통과 완료 */
#include <stdio.h>
#include <string.h>

bool vowel(char str);

int main(void)
{
	char str[100];
	scanf_s("%s", str, 100);

	int idx, len = 0, pIdx;
	for (int i = 0; i < strlen(str); i++) {
		if (i == 0 && !(vowel(str[i]))
			|| vowel(str[i - 1]) && !(vowel(str[i]))) {
			idx = i;
		}
		else if (i == strlen(str) - 1 && !(vowel(str[i]))
			|| vowel(str[i + 1]) && !(vowel(str[i]))) {
			if (len < i - idx + 1) {
				len = i - idx + 1;
				pIdx = idx;
			}
		}
	}

	for (int i = pIdx; i < pIdx + len; i++)
		printf("%c", str[i]);

	return 0;
}

bool vowel(char str) {
	char vo[6] = "aeiou";
	for (int i = 0; i < 5; i++) {
		if (str == vo[i])
			return true;
	}
	return false;
}