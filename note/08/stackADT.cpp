#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"
#define INIT_CAPACITY 100

static void terminate(const char* message)
{
	printf("%s\n", message);
	exit(1);
}

Stack create(char* name)
{
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	if (s == NULL) {
		terminate("Error in creawte: stack could not be created.");
	}
	s->contents = (Item*)malloc(INIT_CAPACITY * sizeof(Item));
	if (s->contents == NULL) {
		free(s);
		terminate("Error in create: stack could not be created.");
	}
	s->top = -1;
	s->size = INIT_CAPACITY;
	s->name = name;
	return s;
}

void destory(Stack s)
{
	free(s->contents);
	free(s);
}

void make_empty(Stack s)
{
	s->top = -1; //������ �迭 ������ ���ذ� �ƴ����� top1 -1�� ���� ����ٰ� �� �� �ִ�.
}

bool is_empty(Stack s)
{
	return s->top == -1; // top�� -1�̸� ����ִٴ� �ǹ�
}

void push(Stack s, Item i)
{
	//if (is_full(s)) {
	//	reallocate(s);
	//}
	s->top++;
	s->contents[s->top] = i;
}

Item pop(Stack s)
{
	if (is_empty(s))
		terminate("Error in pop: stack is empty");
	s->top--;
	return s->contents[s->top + 1];
}

Item peek(Stack s)
{
	if (is_empty(s)) {
		terminate("Error in peek: stack is empty.");
	}
	return s->contents[s->top];
}

void reallocate(Stack s)
{
	Item* tmp = (Item*)malloc(2 * s->size * sizeof(Item));
	if (tmp == NULL) {
		terminate("Error in create: stack could not be created.");
	}
	for (int i = 0; i < s->size; i++) {
		tmp[i] = s->contents[i];
	}
	free(s->contents);
	s->contents = tmp;
	s->size *= 2;
}

bool is_full(Stack s)
{
	return s->top == s->size - 1;
}

void list(Stack s)
{
	for (int i = s->top; i >= 0; i--) {
		printf("%s\n", s->contents[i]);
	}
}