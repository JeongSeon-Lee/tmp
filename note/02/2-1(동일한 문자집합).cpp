/* 1. 영문 소문자로 구성된 2개의 단어를 입력받은 후 두 단어가 동일한 문자집합으로 구성되었는지를 검사
하여 yes 혹은 no를 출력하는 프로그램을 작성하라. 예를 들어 ababc와 cba는 문자집합 {a, b, c}
로 구성되었으므로 yes이다. 입력 단어의 길이는 20이하이다.  */

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

    /* 영문 소문자로만 */
    int flag1[26] = { 0 };
    // 컴파일 타임 초기화
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

    /* word1을 구성하는 문자 집합은 word2 구성하는 문자 집합의 부분 집합, 역도 성립 */
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
        if (!exists)    // s 특정 문자에서 t 모든 문자를 비교했는데 같은 게 없을 때 성립
            return false;
    }

    return true;    // if (!exists)를 불만족했을 때
}

void bsort(char s[]) {
    for (int i = strlen(s) - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (s[j] > s[j + 1]) {      // 아스키 코드든 유니코드든 알파벳순으로 숫자를 부여받음
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