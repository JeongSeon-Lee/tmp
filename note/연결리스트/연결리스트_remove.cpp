#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char* data;
	struct node* next;
};
typedef struct node Node;

Node* head = NULL;

/* ù��° ��� ���� */
Node* remove_first(void);
/* � ����� ���� ��� ���� */
Node* remove_after(Node* prev);
/* index��° ��� ���� */
Node* remove(int index);
/* index��° ��� �˱� */
Node* get_node(int index);
/* ã�� �����Ϳ� ��ġ�ϴ� ��� ���� */
Node* remove(char* item);

int main(void)
{
	head = (Node*)malloc(sizeof(Node));
	head->data = (char*)"aaa";
	head->next = NULL;

	Node* q = head;

	Node* p = (Node*)malloc(sizeof(Node));
	p->data = (char*)"bbb";
	p->next = NULL;
	q->next = p;

	q = p;

	p = (Node*)malloc(sizeof(Node));
	p->data = (char*)"ccc";
	p->next = NULL;
	q->next = p;

	q = p;

	p = (Node*)malloc(sizeof(Node));
	p->data = (char*)"ddd";
	p->next = NULL;
	q->next = p;

	q = p;

	p = (Node*)malloc(sizeof(Node));
	p->data = (char*)"eee";
	p->next = NULL;
	q->next = p;

	remove(1);	// aaa ccc ddd eee
	p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}

	printf("\n");
	remove((char*)"ddd");	// aaa ccc eee
	p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}

	printf("\n");
	remove_first();		// ccc eee
	p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}

	printf("\n");
	remove_after(head);	// ccc
	p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}


	return 0;
}

/* ù��° ��� ���� */
Node* remove_first(void)
{
	if (head == NULL)
		return NULL;
	else {
		Node* tmp = head;
		head = head->next;
		return tmp;
		// free(tmp);
	}
}

/* � ����� ���� ��� ���� */
Node* remove_after(Node* prev)
{
	Node* tmp = prev->next;
	if (tmp == NULL)
		return NULL;
	else {
		prev->next = tmp->next;
		return tmp;
	}
}

/* index��° ��� ���� */
Node* remove(int index)
{
	if (index < 0)
		return NULL;
	if (index == 0)
		return remove_first();
	Node* prev = get_node(index - 1);
	if (prev == NULL)
		return NULL;
	else
		return remove_after(prev);
}
/* index��° ��� �˱� */
Node* get_node(int index)
{
	if (index < 0)
		return NULL;
	Node* p = head;
	for (int i = 0; i < index && p != NULL; i++)
		p = p->next;
	return p;
}

/* ã�� �����Ϳ� ��ġ�ϴ� ��� ���� */
Node* remove(char* item)
{
	Node* p = head, * q = NULL;
	while (p != NULL && strcmp (p->data, item) != 0) {
		q = p;
		p = p->next;
	}
	if (p == NULL)
		return NULL;
	if (q == NULL)
		return remove_first();
	else
		return remove_after(q);
}