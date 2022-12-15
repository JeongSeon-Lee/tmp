#pragma warning (disable:4996)

#include <stdlib.h>
#include <string.h>
#include "stackADT.h"
#include "string_tools.h"

#define MAX_LENGTH 100

// 공백으로 구분되어 있음
// 음이 아닌 정수로 표현된 식

static char OPERATORS[] = "+-*/";

Stack operand_stack;

int eval(char* expr);
int eval_op(char op);
int is_operator(char ch);
void handle_exception(const char* err_msg);

int main(void) {
	printf("글자 사이사이 빈칸 무조건 포함하여 후위표기식을 입력하세요.\n음수와 괄호는 포함하지 마십시오.\n========\n");
	char postfix[MAX_LENGTH];
	read_line(stdin, postfix, MAX_LENGTH);
	printf("%d\n", eval(postfix));
	
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
		if (token[0] >= '0' && token[0] <= '9') {	// 피연산자
			int value = atoi(token);
			push(operand_stack, value);
		}
		else if (is_operator(token[0]) > -1) {		// 연산자
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
	if (is_empty(operand_stack)) // 정상적으로 계산 된 경우
		return answer;
	else {	// 계산이 다 끝났는데도 stack이 비어있지 않은 경우
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