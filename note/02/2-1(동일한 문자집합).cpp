/* 1. ���� �ҹ��ڷ� ������ 2���� �ܾ �Է¹��� �� �� �ܾ ������ ������������ �����Ǿ������� �˻�
�Ͽ� yes Ȥ�� no�� ����ϴ� ���α׷��� �ۼ��϶�. ���� ��� ababc�� cba�� �������� {a, b, c}
�� �����Ǿ����Ƿ� yes�̴�. �Է� �ܾ��� ���̴� 20�����̴�.  */

#include <stdio.h>
#include <string.h>

bool check(char s[], char t[]);
void bsort(char s[]);
void compress(char s[]);

int main(void)
{
    char word1[20], word2[20];
    scanf_s("%s", word1, 20);
    scanf_s("%s", word2, 20);

    /* ���� �ҹ��ڷθ� */
    int flag1[26] = { 0 };
    // ������ Ÿ�� �ʱ�ȭ
    for (int i = 0; i < strlen(word1); i++)
        flag1[word1[i] - 'a'] = 1;
        // a -> 0, b -> 1, ... , z -> 25
    int flag2[26] = { 0 };
    for (int i = 0; i < strlen(word2); i++)
        flag2[word2[i] - 'a'] = 1;

    for (int i = 0; i < 26; i++) {
        if (flag1[i] != flag2[i]) {
            printf("no");
            return 0;
        }
    }
    printf("yes");
    return 0;

    // bsort(word1);
    // bsort(word2);

    // compress(word1);
    // compress(word2);

    // if (strcmp(word1, word2) == 0)
    //     printf("yes");
    // else
    //     printf("no");

    /* word1�� �����ϴ� ���� ������ word2 �����ϴ� ���� ������ �κ� ����, ���� ���� */
    // bool result1 = check(word1, word2);
    // bool result2 = check(word2, word1);
    // if (result1 && result2)
    //     printf("yes");
    // else
    //     printf("no");

    // return 0;
}

bool check(char s[], char t[]) {
    for (int i = 0; i < strlen(s); i++) {
        // check if s[i] belongs to string t
        bool exists = false;
        for (int j = 0; j < strlen(t); j++) {
            if (s[i] == t[j]) {
                exists = true;
                break;
            }
        }
        if (!exists)    // s Ư�� ���ڿ��� t ��� ���ڸ� ���ߴµ� ���� �� ���� �� ����
            return false;
    }

    return true;    // if (!exists)�� �Ҹ������� ��
}

void bsort(char s[]) {
    for (int i = strlen(s) - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (s[j] > s[j + 1]) {      // �ƽ�Ű �ڵ�� �����ڵ�� ���ĺ������� ���ڸ� �ο�����
                char tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }
}

void compress(char s[]) {
    int j = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (i == 0 || s[i] != s[i - 1])    // survive
            s[j++] = s[i];
    }
    s[j] = '\0';
}