/* 통과 완료 */
#include <stdio.h>
#include <string.h>

bool is_palindrome(char word[], int begin, int end) {
	if (begin >= end)
		return true;
	if (word[begin] == word[end] && is_palindrome(word, begin +1, end - 1))
		return true;
	else
		return false;
}

int main(void) {
	char word[100];
	scanf_s("%s", word, 100);
	if (is_palindrome(word, 0, strlen(word) -1))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}