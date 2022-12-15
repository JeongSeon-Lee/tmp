#pragma warning (disable:4996)

#include <stdlib.h>
#include <string.h>
#include "stackADT.h"
#include "string_tools.h"

#define MAX_LENGTH 100

// �������� ���еǾ� ����
// ���� �ƴ� ������ ǥ���� ��

static char OPERATORS[] = "+-*/";
static int PRECEDENCE[] = { 1, 1, 2, 2 };	// ������ �켱����, ū ���� �� ���� �켱����

Stack operand_stack;
Stack operator_stack;

int eval(char* expr);
int eval_op(char op);
int is_operator(char ch);
void handle_exception(const char* err_msg);

char* convert(char* infix);
char* process_op(char op, char* pos);
int precedence(char op);

int main(void) {
	printf("���� ���̻��� ��ĭ ������ �����Ͽ� ����ǥ����� �Է��ϼ���.\n������ ��ȣ�� �������� ���ʽÿ�.\n========\n");
	char infix[MAX_LENGTH];
	read_line(stdin, infix, MAX_LENGTH);
	printf("%s := ", infix);
	char* postfix = convert(infix);
	printf("%s\n", postfix);
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
		if (token[0] >= '0' && token[0] <= '9') {	// �ǿ�����
			int value = atoi(token);
			push(operand_stack, value);
		}
		else if (is_operator(token[0]) > -1) {		// ������
			int result = eval_op(token[0]);
			push(operand_stack, result);
		}
		else {
			handle_exception("Syntax Error: invalid character encountered.");
		}
		token = strtok(NULL, " ");
	}
	if (is_empty(operand_stack))
		handle_exception("Syntax Error: stack empty in eval_op.");
	int answer = pop(operand_stack);
	if (is_empty(operand_stack)) // ���������� ��� �� ���
		return answer;
	else {	// ����� �� �����µ��� stack�� ������� ���� ���
		handle_exception("Syntax Error: stack should be empty.");
		return -1;
	}
}

void handle_exception(const char* err_msg) {
	printf("%s\n", err_msg);
	exit(1);
}

int eval_op(char op) {
	if (is_empty(operand_stack)) {
		handle_exception("Syntax Error: stack empty in eval_op.");
	}
	int rhs = pop(operand_stack);
	if (is_empty(operand_stack))
		handle_exception("Syntax Error: stack empty in eval_op.");
	int lhs = pop(operand_stack);
	int result = 0;
	switch (op) {
	case '+': result = lhs + rhs; break;
	case '-': result = lhs - rhs; break;
	case '*': result = lhs * rhs; break;
	case '/': result = lhs / rhs; break;
	}

	return result;
}

char* convert(char* infix) {
	operator_stack = create();
	char* postfix = (char*)malloc(strlen(infix) + 1);
	char* pos = postfix;	// ���� �� �ڸ�
	char* token = strtok(infix, " ");
	while (token != NULL) {
		if (token[0] >= '0' && token[0] <= '9') {
			sprintf(pos, "%s ", token);
			pos += (strlen(token) + 1);
		}
		else if (is_operator(token[0]) > -1) {
			pos = process_op(token[0], pos);
		}
		else {
			handle_exception("Syntax Error: invalid character encountered.");
		}
		token = strtok(NULL, " ");
	}
	while (!is_empty(operator_stack)) {
		char op = (char)pop(operator_stack);
		sprintf(pos, "%c ", op);
		pos += 2;
	}
	*pos = '\0';
	return postfix;
}

char* process_op(char op, char* pos) {
	if (is_empty(operator_stack))
		push(operator_stack, op);
	else {
		char top_op = peek(operator_stack);
		if (precedence(op) > precedence(top_op))
			push(operator_stack, op);
		else {
			while (!is_empty(operator_stack) && precedence(op) <= precedence(top_op)) {
				pop(operator_stack);	// discard since it's top_op
				sprintf(pos, "%c ", top_op);
				pos += 2;
				if (!is_empty(operator_stack))
					top_op = (char)peek(operator_stack);
			}
			push(operator_stack, op);
		}
	}
	return pos;
}

int precedence(char op) {
	return PRECEDENCE[is_operator(op)];
}