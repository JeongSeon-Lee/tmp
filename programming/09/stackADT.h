#ifndef STACKADT_H
#define STACKADT_H

#include "pos.h"

typedef Position Item;
typedef struct stack_type* Stack;

Stack create();
void destory(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
bool is_full(Stack s);
Item pop(Stack s);
Item peek(Stack s);
void reallocate(Stack s);

#endif