/* 1. �ϳ��� ���� �ҹ��ڷ� �� ���ڿ��� �Է����� �־�����. �� ���ڿ����� ������ ���� ���� �� �����ؼ�
�����ϴ� �κ��� ã�Ƽ� �� �κ��� ����ϴ� ���α׷��� �ۼ��϶�. ���� ��� ���ڿ� ��nietzsche����
���� ��tzsch���� ���� �� ���ӵ� �����̴�. �Է� ���ڿ��� ���̴� 100�����̰�, ��a��, ��e��, ��i��, 
��o��, ��u���� ������ ��� ���ĺ��� �������� �����Ѵ�. */

#include <stdio.h>
#include <string.h>

bool jaum(char c)
{
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void)
{
    char str[100];
    scanf_s("%s", str, 100);
    int len = 0;
    int max_len = 0;
    int max_pos = -1;
    // ���ʿ� ��ȿ���� ���� ��

    // eetghaaabbstruuugdjsadgjaasdg
    // 00123000123450001234012300123

    for (int i = 0; i < strlen(str); i++) {
        if (!jaum(str[i]))
            len = 0;
        else {
            len++;
            if (len > max_len) {
                max_len = len;
                max_pos = i;
            }
        }
    }

    for (int i = 0; i < max_len; i++) {
        printf("%c", str[max_pos - max_len + 1 + i]);
    }
    printf("\n");
}