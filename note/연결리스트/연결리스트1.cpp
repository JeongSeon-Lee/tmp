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
    /* 1. 입력 파일에 등장하는 모든 단어의 목록과 각 단어의 등장 빈도를 구하여 화면으로 출력하는 프로그램
을 작성하라. 단어들은 사전식 순서로 정렬되어 출력되어야 한다. 출력 파일의 각 줄에 하나의 단어와
그 단어의 등장 빈도를 콜론(:)으로 구분하여 출력하라. 동일한 단어가 중복해서 출력되어서는 안된다. 
출력의 마지막 에는 전체 단어의 개수를 출력하라. 아래는 올바른 출력의 시작 부분과 끝 부분을 보여준
다. 단어들은 하나의 연결리스트로 저장되어야 한다. 주의: 파일로부터 단어들을 읽어서 먼저 배열에 모
두 저장한 후 나중에 다시 연결리스트 리스트로 만드는 식으로 해서는 안된다. 단어들은 파일에서 읽는
즉시 연결리스트에 저장되어야 한다. 또한 중복 검사 없이 모든 단어를 연결리스트에 저장한 후 나중에
중복을 제거하는 식으로 해서도 안된다. 연결리스트에는 항상 단어들이 중복없이 저장되어 있도록 구현
해야 한다. */
    char buf[30];
    FILE* fp = 0;
    fopen_s(&fp, "harry.txt", "r");
    while (fscanf_s(fp, "%s", buf, 30) != EOF) {
        Node* p = head, * q = NULL;
        /* 들어갈 노드 포착 */
        while (p != NULL && strcmp(p->word, buf) < 0) {
            // 오름차순으로 정렬하니까 버퍼가 더 커야 지나갈 수 있음
            q = p;
            p = p->next;
        }
        /* 중복된 경우 */
        if (p != NULL && strcmp(p->word, buf) == 0)
            // p가 NULL이라면 p->count는 없음
            p->count++;
        /* 새 노드가 들어가야 할 때 */
        else {
            Node* tmp = (Node*)malloc(sizeof(Node));
            tmp->word = _strdup(buf);
            tmp->count = 1;
            tmp->next = NULL;
            // 널은 넣는 이유는 일단 어디 들어갈 지 모르니까 아래에서 정의
            // 추가하면 리스트의 마지막에 추가해줘야할 경우 생각하지 않아도 됨
            /* add_first */
            if (q == NULL) {
                tmp->next = head;
                // q가 널에서 바뀌지 않으려면 while 조건 불만족
                // 아무런 노드가 없는 경우 || 맨 앞에 삽입해야 하는 경우
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





    /* 2. 1번에서 만든 연결리스트에서 등장 빈도가 10 이하인 모든 단어들을 연결리스트로부터 제거한 후 남
아 있는 단어들만 1번과 같은 형식으로 출력하라. 단어들은 사전식 순서로 정렬되어 있어야 하며, 마지
막에 남아있는 단어들의 개수를 출력한다. */
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




    
    /* 3. 2번에서 만든 연결리스트에서 노드들을 단어들의 등장 빈도의 내림차순으로 정렬하라. 등장 빈도가 동
일한 단어들은 사전식 순서로 정렬되어야 한다. 2번에서 만든 연결리스트에서 노드들을 하나씩 떼어
서 새로운 정렬된 연결리스트에 삽입하는 방식으로 구현하라. 정렬된 연결리스트를 1번과 2번과 같은
형식으로 출력하라. */
    Node* head2 = NULL;
    while (head != NULL) {
        // p가 버퍼, s가 노드를 도는 p, t가 s 따라 다니며 이전 노드를 가리키는 q
        /* 비교할 buf같은 존재 */
        Node* p = head;
        head = head->next;
        p->next = NULL;
        // 널은 넣는 이유는 일단 어디 들어갈 지 모르니까 아래에서 정의
        // head는 계속 다음 노드로 이동
        // p는 head가 이동하기 전 노드를 가리킴

        Node* s = head2, * t = NULL;
        /* 들어가야 할 자리 포착 */
        while (s != NULL && (s->count > p->count
            || (s->count == p->count
                && strcmp(s->word, p->word) < 0))) {
            // 내림차순이니까 내가 더 작을 때 지나갈 수 있음
            // 사전순이니까 내가 더 클 때 지나갈 수 있음 
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