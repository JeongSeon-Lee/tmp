/* 7. �Է����� 100�̸� n���� ���� ���ڿ��� �޴´�. �� ���ڿ��� ���̴� 20�����̴�. �� ���ڿ����� ���ڿ�
�� ���̰� ª�� �Ϳ��� ���� �� �� ������ �����Ͽ� ����϶�. ��, ���̰� ������ ���ڿ����� �׵� ����
������ ������ ���ĵǾ�� �Ѵ�. �Է� ������ ���� ���ڿ��� ���� n�� �־�����, �̾ n���� ���ڿ�
�� �� �ٿ� �ϳ��� �־�����. ���ڿ��� �Է¹޾� �迭�� �����ϴ� ���� main �Լ����� �ϰ�, �����ϴ�
���� ������ �Լ��� ���� ȣ���϶�. �׷� ���� ����ϴ� ���� �ٽ� main�Լ��� ���ƿͼ� �Ѵ�. */

#include <stdio.h>
#include <string.h>

void bubblesort(int n, char* words[]);

int main(void)
{
    char* words[100];
    int n = 0;
    char buf[20];

    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf_s("%s", buf, 20);
        words[i] = _strdup(buf);
    }

    bubblesort(n, words);

    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}

void bubblesort(int n, char* words[])
{
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])
                || (strlen(words[j]) == strlen(words[j + 1])
                    && strcmp(words[j], words[j + 1]) > 0)) {
                char* tmp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = tmp;
            }
        }
    }
}