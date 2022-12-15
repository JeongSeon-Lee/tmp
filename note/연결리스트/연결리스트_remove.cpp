#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char* data;
	struct node* next;
};
typedef struct node Node;

Node* head = NULL;

/* 첫번째 노드 삭제 */
Node* remove_first(void);
/* 어떤 노드의 다음 노드 삭제 */
Node* remove_after(Node* prev);
/* index번째 노드 삭제 */
Node* remove(int index);
/* index번째 노드 알기 */
Node* get_node(int index);
/* 찾는 데이터와 일치하는 노드 삭제 */
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

/* 첫번째 노드 삭제 */
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

/* 어떤 노드의 다음 노드 삭제 */
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

/* index번째 노드 삭제 */
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
/* index번째 노드 알기 */
Node* get_node(int index)
{
	if (index < 0)
		return NULL;
	Node* p = head;
	for (int i = 0; i < index && p != NULL; i++)
		p = p->next;
	return p;
}

/* 찾는 데이터와 일치하는 노드 삭제 */
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