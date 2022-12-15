#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackADT.h"
#include "string_tools.h"

#define MAX_LENGTH 100

// �������� ���еǾ� ����
// ���� �ƴ� ������ ǥ���� ��

static char OPERATORS[] = "+-*/";

Stack operand_stack;

int is_operator(char ch);
int eval(char* expr);
void handle_exception(const char* err_msg);
int eval_op(char op);

int main()
{
	char infix[MAX_LENGTH];
	read_line(stdin, infix, MAX_LENGTH);
	printf(" %s := ", infix);
	char* postfix = strdup(infix);
	printf("%d\n", eval(postfix));

	return 0;
}

int is_operator(char ch) {
	for (int i = 0; i < strlen(OPERATORS); i++) {
		if (OPERATORS[i] == ch) {
			return i;
		}
	}
	return -1;
}

int eval(char* expr) {
	operand_stack = create();
	char* token = strtok(expr, " ");
	while (token != NULL) {
		if (token[0] >= '0' && token[0] <= '9') { //digit
			int value = atoi(token);
			push(operand_stack, value);
		}
		else if (is_operator(token[0]) > -1) { // �������� ���
			int result = eval_op(token[0]);
			push(operand_stack, result);
		}
		else {
			handle_exception("Syntax Error: invalid character encountered");
		}
		token = strtok(NULL, " ");
	}
	if (is_empty(operand_stack))
		handle_exception("Syntax Error: Stack empty in eval_op.");
	int answer = pop(operand_stack);
	if (is_empty(operand_stack)) // ���������� ��� �� ���
		return answer;
	else { // ����� �� �����µ��� stack�� ������� ���� ���
		handle_exception("Syntax Error: Stack should be empty");
		return -1;
	}
}

void handle_exception(const char* err_msg) {
	printf("%s\n", err_msg);
	exit(1);
}


int eval_op(char op) {
	if (is_empty(operand_stack)) {
		handle_exception("Syntax Error: Stack empty in eval_op.");
	}
	int rhs = pop(operand_stack);
	if (is_empty(operand_stack))
		handle_exception("Syntax Error: Stack empty in eval_op.");
	int lhs = pop(operand_stack);
	int result = 0;
	switch (op) {
	case '+':
		result = lhs + rhs;
		break;
	case '-':
		result = lhs - rhs;
		break;
	case '*':
		result = lhs * rhs;
		break;
	case '/':
		result = lhs / rhs;
		break;
	}

	return result;
}