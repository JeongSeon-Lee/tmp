/* 통과 완료 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char* word;
    int num;
    struct node* next;
};
typedef struct node Node;

Node* head = NULL;
Node* head3 = NULL;

void print(Node* head);
void Sort_without_duplication(void);
Node* remove(char* item);
Node* remove_first();
Node* remove_after(Node* prev);
void Sort3(void);

int main(void)
{
    /* 1번 */
    Sort_without_duplication();
    print(head);

    /* 2번 */
    printf("\n");
    Node* p = head;
    while (p != NULL) {
        if (p->num <= 10)
            remove(p->word);
        p = p->next;
    }
    print(head);

    /* 3번 */
    printf("\n");
    Sort3();
    print(head3);

    return 0;
}

void print(Node* head)
{
    int count = 0;
    Node* p = head;
    while (p != NULL) {
        printf("%s: %d\n", p->word, p->num);
        p = p->next;
        count++;
    }
    printf("%d\n", count);
}
void Sort_without_duplication(void)
{
    char buf[30];
    FILE* fp = 0;
    fopen_s(&fp, "harry.txt", "r");

    Node* p = NULL;
    Node* q = NULL;
    Node* tmp = NULL;
    while (fscanf_s(fp, "%s", buf, 30) != EOF) {
        bool duplicate = false;
        p = head;
        q = NULL;
        while (head != NULL && p != NULL) {
            if (strcmp(p->word, buf) == 0) {
                p->num++;
                duplicate = true;
                break;
            }
            else if (strcmp(p->word, buf) > 0)
                break;
            q = p;
            p = p->next;
        }

        if (!duplicate) {
            tmp = (Node*)malloc(sizeof(Node));
            tmp->word = _strdup(buf);
            tmp->num = 1;
            if (head == NULL) {    // 연결리스트에 아무 노드가 없는 경우
                tmp->next = NULL;
                head = tmp;
            }
            else if (p == NULL) {  // 연결리스트 마지막 노드에 들어가야 하는 경우
                tmp->next = NULL;
                q->next = tmp;
            }
            else if (q == NULL) {  // 연결리스트 첫번째 노드에 들어가야 하는 경우
                    tmp->next = p;
                    head = tmp;
            }
            else {
                tmp->next = p;
                q->next = tmp;
            }
        }
    }
    fclose(fp);
}

Node* remove(char* item)
{
    Node* p = head;
    Node* q = NULL;
    while (p != NULL && strcmp(p->word, item) != 0) {
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

Node* remove_first()
{
    if (head == NULL)
        return NULL;
    else {
        Node* tmp = head;
        head = head->next;
        return tmp;
    }
}

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

void Sort3(void)
{
    Node* r = head;
    Node* p = NULL;
    Node* q = NULL;
    Node* tmp = NULL;
    
    while (r != NULL) {
        p = head3;
        q = NULL;
        while (head3 != NULL && p != NULL) {
            if ((p->num == r->num && strcmp(p->word, r->word) > 0) 
                     || p->num < r->num)
                break;
            q = p;
            p = p->next;
        }

        tmp = (Node*)malloc(sizeof(Node));
        tmp->word = r->word;
        tmp->num = r->num;
        if (head3 == NULL) {
            tmp->next = NULL;
            head3 = tmp;
        }
        else if (p == NULL) {
            tmp->next = NULL;
            q->next = tmp;
        }
        else if (q == NULL) {
            tmp->next = p;
            head3 = tmp;
        }
        else {
            tmp->next = p;
            q->next = tmp;
        }

        r = r->next;
    }
}