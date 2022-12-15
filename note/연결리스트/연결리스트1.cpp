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
    /* 1. �Է� ���Ͽ� �����ϴ� ��� �ܾ��� ��ϰ� �� �ܾ��� ���� �󵵸� ���Ͽ� ȭ������ ����ϴ� ���α׷�
�� �ۼ��϶�. �ܾ���� ������ ������ ���ĵǾ� ��µǾ�� �Ѵ�. ��� ������ �� �ٿ� �ϳ��� �ܾ��
�� �ܾ��� ���� �󵵸� �ݷ�(:)���� �����Ͽ� ����϶�. ������ �ܾ �ߺ��ؼ� ��µǾ�� �ȵȴ�. 
����� ������ ���� ��ü �ܾ��� ������ ����϶�. �Ʒ��� �ùٸ� ����� ���� �κа� �� �κ��� ������
��. �ܾ���� �ϳ��� ���Ḯ��Ʈ�� ����Ǿ�� �Ѵ�. ����: ���Ϸκ��� �ܾ���� �о ���� �迭�� ��
�� ������ �� ���߿� �ٽ� ���Ḯ��Ʈ ����Ʈ�� ����� ������ �ؼ��� �ȵȴ�. �ܾ���� ���Ͽ��� �д�
��� ���Ḯ��Ʈ�� ����Ǿ�� �Ѵ�. ���� �ߺ� �˻� ���� ��� �ܾ ���Ḯ��Ʈ�� ������ �� ���߿�
�ߺ��� �����ϴ� ������ �ؼ��� �ȵȴ�. ���Ḯ��Ʈ���� �׻� �ܾ���� �ߺ����� ����Ǿ� �ֵ��� ����
�ؾ� �Ѵ�. */
    char buf[30];
    FILE* fp = 0;
    fopen_s(&fp, "harry.txt", "r");
    while (fscanf_s(fp, "%s", buf, 30) != EOF) {
        Node* p = head, * q = NULL;
        /* �� ��� ���� */
        while (p != NULL && strcmp(p->word, buf) < 0) {
            // ������������ �����ϴϱ� ���۰� �� Ŀ�� ������ �� ����
            q = p;
            p = p->next;
        }
        /* �ߺ��� ��� */
        if (p != NULL && strcmp(p->word, buf) == 0)
            // p�� NULL�̶�� p->count�� ����
            p->count++;
        /* �� ��尡 ���� �� �� */
        else {
            Node* tmp = (Node*)malloc(sizeof(Node));
            tmp->word = _strdup(buf);
            tmp->count = 1;
            tmp->next = NULL;
            // ���� �ִ� ������ �ϴ� ��� �� �� �𸣴ϱ� �Ʒ����� ����
            // �߰��ϸ� ����Ʈ�� �������� �߰�������� ��� �������� �ʾƵ� ��
            /* add_first */
            if (q == NULL) {
                tmp->next = head;
                // q�� �ο��� �ٲ��� �������� while ���� �Ҹ���
                // �ƹ��� ��尡 ���� ��� || �� �տ� �����ؾ� �ϴ� ���
                head = tmp;
            }
            /* add_after */
            else {
                tmp->next = q->next;
                q->next = tmp;
            }
        }
    }
    fclose(fp);

    printf("Answer1:\n");
    Node* p = head;
    int c = 0;
    while (p != NULL) {
        printf("%s: %d\n", p->word, p->count);
        p = p->next;
        c++;
    }
    printf("%d\n", c);





    /* 2. 1������ ���� ���Ḯ��Ʈ���� ���� �󵵰� 10 ������ ��� �ܾ���� ���Ḯ��Ʈ�κ��� ������ �� ��
�� �ִ� �ܾ�鸸 1���� ���� �������� ����϶�. �ܾ���� ������ ������ ���ĵǾ� �־�� �ϸ�, ����
���� �����ִ� �ܾ���� ������ ����Ѵ�. */
    p = head;
    Node* q = NULL;
    while (p != NULL) {
        if (p->count <= 10) {
            /* remove_first */
            if (q == NULL)
                head = head->next;
            /* remove_after */
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
        c++;
    }
    printf("%d\n", c);




    
    /* 3. 2������ ���� ���Ḯ��Ʈ���� ������ �ܾ���� ���� ���� ������������ �����϶�. ���� �󵵰� ��
���� �ܾ���� ������ ������ ���ĵǾ�� �Ѵ�. 2������ ���� ���Ḯ��Ʈ���� ������ �ϳ��� ����
�� ���ο� ���ĵ� ���Ḯ��Ʈ�� �����ϴ� ������� �����϶�. ���ĵ� ���Ḯ��Ʈ�� 1���� 2���� ����
�������� ����϶�. */
    Node* head2 = NULL;
    while (head != NULL) {
        // p�� ����, s�� ��带 ���� p, t�� s ���� �ٴϸ� ���� ��带 ����Ű�� q
        /* ���� buf���� ���� */
        Node* p = head;
        head = head->next;
        p->next = NULL;
        // ���� �ִ� ������ �ϴ� ��� �� �� �𸣴ϱ� �Ʒ����� ����
        // head�� ��� ���� ���� �̵�
        // p�� head�� �̵��ϱ� �� ��带 ����Ŵ

        Node* s = head2, * t = NULL;
        /* ���� �� �ڸ� ���� */
        while (s != NULL && (s->count > p->count
            || (s->count == p->count
                && strcmp(s->word, p->word) < 0))) {
            // ���������̴ϱ� ���� �� ���� �� ������ �� ����
            // �������̴ϱ� ���� �� Ŭ �� ������ �� ���� 
            t = s;
            s = s->next;
        }
        /* add_first */
        if (t == NULL) {
            p->next = head2;
            head2 = p;
        }
        /* add_after */
        else {
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
        c++;
    }
    printf("%d\n", c);

    return 0;
}