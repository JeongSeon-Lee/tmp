#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char* data;
	struct node* next;
};
typedef struct node Node;

/* head가 전역변수인 경우 */
Node* head = NULL;

/* 연결리스트 맨 앞 노드 삽입 */
void add_first(char* item);
/* 어떤 노드 뒤에 새로운 노드 삽입 */
int add_after(Node* prev, char* item);
/* 연결리스트의 index번째 위치에 새로운 노드를 만들어서 삽입 */
int add(int index, char* item);
/* 연결리스트 index번째 노드의 주소를 반환 */
Node* get_node(int index);
/* 순서에 맞게 추가하기 */
void add_to_ordered_list(char* item);
/* head가 전역변수가 아닌 경우 방법 1 */
Node* add_first(Node* head, char* item);
/* head가 전역변수가 아닌 경우 방법 2 */
void add_first(Node** ptr_head, char* item);

int main(void)
{
	head = (Node*)malloc(sizeof(Node));
	head->data = (char*)"Henry";	// Henry, "C에서는 문자열 리터럴이 char의 배열이지만, C++에서는 const char의 배열이다."
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

/* 연결리스트 맨 앞 노드 삽입 */
void add_first(char* item)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = head;
	head = tmp;
}

/* 어떤 노드 뒤에 새로운 노드 삽입 */
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

/* 연결리스트의 index번째 위치에 새로운 노드를 만들어서 삽입 */
int add(int index, char* item)
{
	// 노드를 추가할 때는 맨 앞에 넣느냐와 어떤 노드 뒤에 넣느냐로 나뉜다.
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
/* 연결리스트 index번째 노드의 주소를 반환 */
Node* get_node(int index)
{
	if (index < 0)
		return NULL;
	Node* p = head;
	for (int i = 0; i < index && p != NULL; i++)
		p = p->next;
	return p;
}

/* 순서에 맞게 추가하기 */
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

/* head가 전역변수가 아닌 경우 방법 1 */
Node* add_first(Node* head, char* item)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = head;
	return tmp;
}

/* head가 전역변수가 아닌 경우 방법 2 */
void add_first(Node** ptr_head, char* item)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = *ptr_head;
	*ptr_head = tmp;
}