/* 2. ���� �Էµ� ������ ���� 2�̻� 100���� n�� �Է¹ް�, �̾ ���� ������ �Է¹޴´�. �Էµ� ������ ��
���� �ּҰ��� �ι�°�� ���� ���� ã�� ����ϴ� ���α׷��� �ۼ��϶�. ���� �ּҰ��� 2�� �̻� �ߺ�
�Ǿ� �����ϸ� �� �� �ϳ��� �ּҰ�����, �ٸ� �ϳ��� �� ��°�� ���� ������ �����Ѵ�. */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int num[100];  /* �迭�� ���̸� ������ ���� �� �� ����, Ȥ�� ���� �޸� �Ҵ�,
    ���� �������� 100�̴ϱ�, 100������ �޸� �Һ� ����, ������� ���� �Ű� ����� �� */
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &num[i]);
    }

    /* �ּڰ��� ���־��־��� �⺻���� ����, �������� �ʰ� �� ���� */
    int theMin;
    int theSecond;
    if (num[0] <= num[1]) {
        theMin = num[0];
        theSecond = num[1];
    }
    else {
        theMin = num[1];
        theSecond = num[0];
    }
    for (int i = 2; i < n; i++) {
        if (num[i] <= theMin) {     // =
            theSecond = theMin;     // ���� �ּҰ��� ���������� ��
            theMin = num[i];
        }
        else if (num[i] < theSecond) {  // theSecond > num[i] > theMin
            theSecond = num[i];
        }
    }
    printf("%d %d\n", theMin, theSecond);
    return 0;
}