#ifndef STACK_H
#define STACK_H

#include <string.h>
#include <stdio.h>

#define MAX_CAPACITY 100

char stack[MAX_CAPACITY];
int top = -1;

int is_full();
int is_empty();

void push(char ch)
{
	if (is_full())
		return;
	top++;
	stack[top] = ch;
}

char pop()
{
	if (is_empty())
		return 'A';
	char tmp = stack[top];
	top--;
	return tmp;
}

char peek()
{
	return stack[top];
}

int is_empty()
{
	return top == -1;
}

int is_full()
{
	return top == MAX_CAPACITY - 1;
}

#endif