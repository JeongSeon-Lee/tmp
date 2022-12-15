/* 통과 완료 */
#include <stdio.h>

#define SIZE 50

int main(void)
{
	char input, stack[SIZE];
	int idx = 0, count = 0;

    do {
        scanf("%c", &input);
        if (input == '(') {
			stack[idx++] = ++count;
			printf("%d ", count);
		}
		else if (input == ')') {
			idx--;
			printf("%d ", stack[idx]);
		}
    } while (input)
	while (scanf("%c", &input) != '\n') {
		if (input == '(') {
			stack[idx++] = ++count;
			printf("%d ", count);
		}
		else if (input == ')') {
			idx--;
			printf("%d ", stack[idx]);
		}
	}
	return 0;
}