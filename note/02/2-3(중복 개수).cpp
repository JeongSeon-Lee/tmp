/* 3. �Է����� �ؽ�Ʈ ���� harry.txt�� �д´�. �� �ؽ�Ʈ ������ ���� ���� �ҹ��ڸ����� �����Ǿ� ��
��. �� ���Ͽ� �����ϴ� ���̰� 6�̻��� ��� �ܾ��� ��ϰ� �� �ܾ��� ���� �󵵸� ���Ͽ� ȭ������ ��
���ϴ� ���α׷��� �ۼ��϶�. �ܾ���� ������ ������ ���ĵǾ� ��µǾ�� �Ѵ�. ��� ������ �� �ٿ�
�ϳ��� �ܾ�� �� �ܾ��� ���� �󵵸� �ݷ�(:)���� �����Ͽ� ����϶�. ������ �ܾ �ߺ��ؼ� ��µ�
��� �ȵȴ�. �ܾ���� ���� �����̵� 16�������� ���� �ڷᱸ���� ����Ǿ�� �Ѵ�. ����� ������
���� ��ü �ܾ��� ������ ����϶�. �Ʒ��� �ùٸ� ����� ���� �κа� �� �κ��� �����ش�. */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char* words[100000];
    int counter[100000] = { 0 };   // �����Ϸ��� �Ϲ������� ��������, 0���� �ʱ�ȭ�ϴ� ���� ����
    int n = 0;
    char buf[40];
    FILE* fp = 0;
    fopen_s(&fp, "harry.txt", "r");
    while (fscanf_s(fp, "%s", buf, 40) != EOF) {
        if (strlen(buf) < 6)
            continue;
        /* �ߺ� ���ſ� �������� */
        bool duplicate = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(buf, words[i]) == 0) {
                duplicate = true;
                counter[i]++;
                break;
            }
        }
        if (!duplicate) {
            int j = n - 1;
            while (j >= 0 && strcmp(buf, words[j]) < 0) {
                words[j + 1] = words[j];
                counter[j + 1] = counter[j];
                j--;
            }
            words[j + 1] = _strdup(buf);
            counter[j + 1] = 1;
            n++;
        }
    }
    fclose(fp);
 
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i], counter[i]);
    }
    printf("%d", n);


    return 0;
}