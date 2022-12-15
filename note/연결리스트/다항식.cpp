#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POLYS 10
#define BUFFER_LENGTH 30

/* 항 */
struct term {
	int coef;
	int expo;
	struct term* next;
};
typedef struct term Term;

/* 함수 */
typedef struct polynomial {
	char name;
	Term* first;
	int size;
} Polynomial;

/* 함수 배열 */
Polynomial* polys[MAX_POLYS];
int n = 0;

/* 객체 생성 */
Term* creat_term_instance(void);
Polynomial* creat_polynomial_instance(char name);

int main(void)
{
	return 0;
}

/* 객체 생성 */
Term* creat_term_instance(void)
{
	Term* t = (Term*)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	t->next = NULL;
	return t;
}
Polynomial* creat_polynomial_instance(char name)
{
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;
}

void process_command(void)
{
	char command_line[BUFFER_LENGTH];
	char copied[BUFFER_LENGTH];
	char* command, * arg1, * arg2;

	while (1) {
		printf("$ ");
		if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)
			continue;
		strcpy(copied, command_line);
		command = strtok(command_line, " ");
		if (strcmp(command, "print") == 0) {
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			handle_print(arg1[0]);
		}
	}
}