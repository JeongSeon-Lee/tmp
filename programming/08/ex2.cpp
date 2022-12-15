#include <stdio.h>
#include <string.h>
#include "stackADT.h"

//#define CHAR_SIZE 50
//#define STACK_SIZE 100
//
//typedef struct stack_type Stack;
//typedef struct node Node;
//
//struct stack_type {
//	char* name;
//	Node* top;
//	int size;
//};
//
//struct node {
//	char* data;
//	struct node* next;
//};
//
//Stack* stackAry[STACK_SIZE];
//int stackCount = 0;

Stack stacks[100];
int num_stack = 0;

Stack find_stack(char* name) {
	for (int i = 0; i < num_stack; i++) {
		if (strcmp(stacks[i]->name, name) == 0)
			return stacks[i];
	}
}

//int read_line(FILE* fp, char str[], int n);
//void create(char* name);
//void push(char* name, char* item);
//void list(char* name);
//void pop(char* name);
//int stackSearch(char* name);

int main(void)
{
	char command[20], stackname[20], str[20];
	//char command_line[CHAR_SIZE];
	//char* command, * argument1, * argument2;
	//char* context = NULL;

	while (1) {
		printf("$ ");
		scanf_s("%s", command, 20);

		//if (read_line(stdin, command_line, CHAR_SIZE) <= 0)
		//	continue;

		//command = strtok_s(command_line, " ", &context);
		if (strcmp(command, "create") == 0) {
			//argument1 = strtok_s(NULL, " ", &context);
			//if (argument1 == NULL) {
			//	printf("Invalid arguments.\n");
			//	continue;
			//}
			//create(argument1);
			scanf_s("%s", stackname, 20);
			Stack s = create(_strdup(stackname));
			stacks[num_stack++] = s;
		}
		else if (strcmp(command, "push") == 0) {
			//argument1 = strtok_s(NULL, " ", &context);
			//if (argument1 == NULL) {
			//	printf("Invalid arguments.\n");
			//	continue;
			//}
			//argument2 = strtok_s(NULL, " ", &context);
			//if (argument2 == NULL) {
			//	printf("Invalid arguments.\n");
			//	continue;
			//}
			//push(argument1, argument2);
			scanf_s("%s", stackname, 20);
			Stack s = find_stack(stackname);
			if (s == NULL) {
				printf("No such stack.\n");
				continue;
			}
			scanf_s("%s", str, 20);
			push(s, _strdup(str));
		}
		else if (strcmp(command, "pop") == 0) {
			//argument1 = strtok_s(NULL, " ", &context);
			//if (argument1 == NULL) {
			//	printf("Invalid arguments.\n");
			//	continue;
			//}
			//pop(argument1);
			scanf_s("%s", stackname, 20);
			Stack s = find_stack(stackname);
			if (s == NULL) {
				printf("No such stack.\n");
				continue;
			}
			printf("%s\n", pop(s));
		}
		else if (strcmp(command, "list") == 0) {
			//argument1 = strtok_s(NULL, " ", &context);
			//if (argument1 == NULL) {
			//	printf("Invalid arguments.\n");
			//	continue;
			//}
			//list(argument1);
			scanf_s("%s", stackname, 20);
			Stack s = find_stack(stackname);
			if (s == NULL) {
				printf("No such stack.\n");
				continue;
			}
			list(s);
		}
		else if (strcmp(command, "exit") == 0)
			break;
	}

	return 0;
}

//int read_line(FILE* fp, char str[], int n) {
//	int ch, i = 0;
//	while ((ch = fgetc(fp)) != '\n' && ch != EOF)
//		if (i < n - 1)
//			str[i++] = ch;
//	str[i] = '\0';
//	return i;
//}
//
//void create(char* name)
//{
//	Stack* s = (Stack*)malloc(sizeof(Stack));
//	if (s == NULL) {
//		printf("스택 생성 실패");
//		return;
//	}
//	s->name = _strdup(name);
//	s->top = NULL;
//	s->size = 0;
//	stackAry[stackCount] = s;
//	stackCount++;
//}
//
//void push(char* name, char* item)
//{
//	int i = stackSearch(name);
//	if (i < 0)
//		return;
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = _strdup(item);
//	p->next = stackAry[i]->top;
//	stackAry[i]->top = p;
//	stackAry[i]->size++;
//}
//
//void list(char* name)
//{
//	int i = stackSearch(name);
//	if (i < 0)
//		return;
//	Node* p = stackAry[i]->top;
//	while (p != NULL) {
//		printf("%s\n", p->data);
//		p = p->next;
//	}
//}
//
//void pop(char* name)
//{
//	int i = stackSearch(name);
//	if (i < 0)
//		return;
//	Node* tmp = stackAry[i]->top;
//	printf("%s\n", tmp->data);
//	stackAry[i]->top = tmp->next;
//	free(tmp);
//}
//
//int stackSearch(char* name)
//{
//	int i;
//	for (i = 0; i < stackCount; i++) {
//		if (strcmp(stackAry[i]->name, name) == 0) {
//			return i;
//		}
//	}
//	if (i == stackCount && strcmp(stackAry[i - 1]->name, name) != 0) {
//		printf("그런 이름의 스택은 없음\n");
//		return -1;
//	}
//}