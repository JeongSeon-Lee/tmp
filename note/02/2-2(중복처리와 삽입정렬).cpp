/* 2. �Է����� �ؽ�Ʈ ���� harry.txt�� �о �� ���Ͽ� �����ϴ� ��� �ܾ��� ����� �ߺ��� �ܾ��
�� ������ ������ �����Ͽ� ���� �����̵� 16�������� ���� �ڷᱸ���� �����Ѵ�. ���� ���ο� �ܾ� ��
���� Ű����κ��� �Է¹޴´�. ����� �ܾ�� �߿� �� ���ο� �ܾ ���ξ�(prefix)�� �ϴ� ��� �ܾ�
�� ã�Ƽ� �� �ٿ� �ϳ��� ����ϴ� ���α׷��� �ۼ��϶�. ���������� ã���� �ܾ��� ������ ����϶�.
� �ܾ �ٸ� �ܾ��� ���ξ������� ǥ�� ���̺귯���� �����ϴ� strncmp �Լ��� �̿��Ͽ� �˻�
�� �� �ִ�. �� �Լ��� ��� ����� �˻��Ͽ� �˾ƺ���. */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char* words[100000];
    int n = 0;
    char buf[40];
    FILE* fp = 0;
    fopen_s(&fp, "harry.txt", "r");
    while (fscanf_s(fp, "%s", buf, 40) != EOF) {
        bool duplicate = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(buf, words[i]) == 0) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            int j = n - 1;
            while (j >= 0 && strcmp(buf, words[j]) < 0) {
                words[j + 1] = words[j];
                j--;
            }
            words[j + 1] = _strdup(buf);
            n++;
        }
    }
    fclose(fp);

    char prefix[40];
    scanf_s("%s", prefix, 40);
    int pref_count = 0;
    for (int i = 0; i < n; i++) {
        if (strncmp(prefix, words[i], strlen(prefix)) == 0) {
            printf("%s\n", words[i]);
            pref_count++;
        }
    }
    printf("%d\n", pref_count);

    return 0;
}