#include <stdio.h>
#include <stdlib.h>
#include "stackADTList.h"

#define INIT_CAPACITY 100

struct node {
	Item data;
	struct node* next;
};

struct stack_type {
	struct node* top;
};

static void terminate(const char* message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create()
{
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	if (s == NULL) {
		terminate("Error in creawte: stack could not be created.");
	}
	s->top = NULL;
	return s;
}

void destory(Stack s)
{
	make_empty(s);
	free(s);
}

void make_empty(Stack s)
{
	while (!is_empty(s))
		pop(s);
}

bool is_empty(Stack s)
{
	return s->top == NULL; // top이 -1이면 비어있다는 의미
}

void push(Stack s, Item i)
{
	struct node* new_node = (struct node *)malloc(sizeof(struct node));
	if (new_node == NULL) {
		terminate("Error in push: stack is full.");
	}
	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;
}

Item pop(Stack s)
{
	struct node* old_top;
	Item i;
	if (is_empty(s))
		terminate("Error in pop: stack is empty");
	old_top = s->top;
	i = old_top->data;
	s->top = old_top->next;
	free(old_top);
	return i;
}

Item peek(Stack s)
{
	if (is_empty(s)) {
		terminate("Error in peek: stack is empty.");
	}
	return s->top->data;
}