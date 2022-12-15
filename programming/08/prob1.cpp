/* 통과 완료 */
#include <stdio.h>
#include <string.h>

#define SIZE 50

int main(void)
{
	char input[SIZE], stack[SIZE];
	int idx = 0, count = 0;
	scanf_s("%s", input, SIZE);
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '(') {
			stack[idx++] = ++count;
			printf("%d ", count);
		}
		else if (input[i] == ')') {
			idx--;
			printf("%d ", stack[idx]);
		}
	}
	return 0;
}