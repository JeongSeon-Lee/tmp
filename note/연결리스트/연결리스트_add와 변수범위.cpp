#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char* data;
	struct node* next;
};
typedef struct node Node;

/* head�� ���������� ��� */
Node* head = NULL;

/* ���Ḯ��Ʈ �� �� ��� ���� */
void add_first(char* item);
/* � ��� �ڿ� ���ο� ��� ���� */
int add_after(Node* prev, char* item);
/* ���Ḯ��Ʈ�� index��° ��ġ�� ���ο� ��带 ���� ���� */
int add(int index, char* item);
/* ���Ḯ��Ʈ index��° ����� �ּҸ� ��ȯ */
Node* get_node(int index);
/* ������ �°� �߰��ϱ� */
void add_to_ordered_list(char* item);
/* head�� ���������� �ƴ� ��� ��� 1 */
Node* add_first(Node* head, char* item);
/* head�� ���������� �ƴ� ��� ��� 2 */
void add_first(Node** ptr_head, char* item);

int main(void)
{
	head = (Node*)malloc(sizeof(Node));
	head->data = (char*)"Henry";	// Henry, "C������ ���ڿ� ���ͷ��� char�� �迭������, C++������ const char�� �迭�̴�."
	head->next = NULL;
	Node* p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}

	printf("\n");
	add_first((char*)"Adam");	// Adam Henry
	p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}

	printf("\n");
	add(1, (char*)"Baker");		// Adam Baker Henry
	p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}

	printf("\n");
	add_after(head->next->next, (char*)"Tom");	// Adam Baker Henry Tom
	p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}

	printf("\n");
	add_to_ordered_list((char*)"David");	// Adam Baker David Henry Tom
	p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}

	return 0;
}

/* ���Ḯ��Ʈ �� �� ��� ���� */
void add_first(char* item)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = head;
	head = tmp;
}

/* � ��� �ڿ� ���ο� ��� ���� */
int add_after(Node* prev, char* item)
{
	if (prev == NULL)
		return 0;
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = prev->next;
	prev->next = tmp;
	
	return 1;
}

/* ���Ḯ��Ʈ�� index��° ��ġ�� ���ο� ��带 ���� ���� */
int add(int index, char* item)
{
	// ��带 �߰��� ���� �� �տ� �ִ��Ŀ� � ��� �ڿ� �ִ��ķ� ������.
	if (index < 0)
		return 0;
	if (index == 0) {
		add_first(item);
		return 1;
	}
	Node* prev = get_node(index - 1);
	if (prev != NULL) {
		add_after(prev, item);
		return 1;
	}
}
/* ���Ḯ��Ʈ index��° ����� �ּҸ� ��ȯ */
Node* get_node(int index)
{
	if (index < 0)
		return NULL;
	Node* p = head;
	for (int i = 0; i < index && p != NULL; i++)
		p = p->next;
	return p;
}

/* ������ �°� �߰��ϱ� */
void add_to_ordered_list(char* item)
{
	Node* p = head, * q = NULL;
	while (p != NULL && strcmp(p->data, item) <= 0) {
		q = p;
		p = p->next;
	}
	if (q == NULL)
		add_first(item);
	else
		add_after(q, item);
}

/* head�� ���������� �ƴ� ��� ��� 1 */
Node* add_first(Node* head, char* item)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = head;
	return tmp;
}

/* head�� ���������� �ƴ� ��� ��� 2 */
void add_first(Node** ptr_head, char* item)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = *ptr_head;
	*ptr_head = tmp;
}