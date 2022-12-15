#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char* word;
    int count;
    struct node* next;
};
typedef struct node Node;
Node* head = NULL;

int main(void)
{
    char buf[30];
    FILE *fp = fopen("harry.txt", "r");
    while (fscanf(fp, "%s", buf) != EOF) {
/*         Node*p = head;
        while (p!=NULL && strcmp(p->word, buf) != 0) // 첫번째 조건 불만족으로 빠져나옴 || 두번째 조건 불만족으로 빠져나옴
            // compare p->word and buf
            p = p->next;
        if (p != NULL)
            p->count++;
        else {
            Node * t = (Node *)malloc(sizeof(Node));
            t->word = strdup(buf);
            t->count = 1;
            t->next = NULL; // 일단 어디 들어가야 할 지 모르니까
        }
        // 여기서 새로 만든 노드를 어디에 끼워넣을지 순회를 또 해야하는데 위에서도 순회를 하니까 비효율적 */

        Node *p = head, *q = NULL;
        while (p!=NULL && strcmp(p->word, buf) < 0) { // 같은 단어나 더 큰 단어를 만났을 때 빠져나오도록 
            // compare p->word and buf
            q = p;
            p = p->next;
        }
        if (p != NULL && strcmp(p->word, buf) == 0)
            p->count++;
        else {
            Node * t = (Node *)malloc(sizeof(Node));
            t->word = strdup(buf);
            t->count = 1;
            t->next = NULL; // 일단 어디 들어가야 할 지 모르니까
            if (q == NULL) {    // while 들어가지 않았을 때, 맨 앞
                t->next = head;
                head = t;
            }
            else {
                t->next = q->next;
                q->next = t;
            }
        }
    }
    fclose(fp);

    printf("Answer1:\n");
    Node *p = head;
    int c = 0;
    while (p != NULL) {
        printf("%s: %d\n", p->word, p->count);
        p = p->next;
    }
    printf("%d\n", c);


    // problem 6-2
    
    p = head;
    Node *q = NULL;
    while (p != NULL) {
        if (p->count <= 10) {
            // remove node p, removeAfter(q)
            if (q == NULL)
                head = head->next;  // head = p;
            else
                q->next = p->next;
        }
        else
            q = p;
        p = p->next;

    }

    printf("Answer2:\n");
    p = head;
    c = 0;
    while (p != NULL) {
        printf("%s: %d\n", p->word, p->count);
        p = p->next;
    }
    printf("%d\n", c);

    // problem 6-3
    // insertion sort

    Node *head2 = NULL;
    while (head != NULL) {
        Node *p= head;
        head = head->next;
        p->next = NULL;

        Node *s = head2, *t = NULL;
        while (s!=NULL && (s->count > p->count || 
                (s->count == p->count &&
                strcmp(s->word, p->word) < 0))) {
            t= s;
            s = s->next;
        }
        if (t == NULL) {    // addFirst
            p->next = head2;
            head2 = p;
        }
        else {              // addAfter
            p->next = t->next;
            t->next = p;
        }
    }

    printf("Answer3:\n");
    p = head2;
    c = 0;
    while (p != NULL) {
        printf("%s: %d\n", p->word, p->count);
        p = p->next;
    }
    printf("%d\n", c);

    return 0;
}
