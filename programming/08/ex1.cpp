// ex01
#include <stdio.h>
#include <string.h>
#include "stackADT.h"

int stack[100];
int top = -1;
void push(int x) {
	top++;
	stack[top] = x;
}
int pop() {
	top--;
	return stack[top + 1];
}

int main(void)
{
	char input[100];
	scanf_s("%s", input, 100);
	int count = 0;
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '(') {
			count++;
			printf("%d ", count);
			push(count);
			//stack[idx++] = ++count;
			//printf("%d ", count);
		}
		else if (input[i] == ')') {
			printf("%d ", pop());
			//idx--;
			//printf("%d ", stack[idx]);
		}
	}
	return 0;
}