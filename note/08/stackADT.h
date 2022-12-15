#ifndef STACKADT_H
#define STACKADT_H

typedef char * Item;
typedef struct stack_type* Stack;

struct stack_type {
	Item* contents; //stack ������ �ϴ� �迭
	int top;
	int size; // �迭�� ũ��
	char* name;
};

Stack create(char* name);
void destory(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
bool is_full(Stack s);
Item pop(Stack s);
Item peek(Stack s);
void reallocate(Stack s);
void list(Stack s);

#endif