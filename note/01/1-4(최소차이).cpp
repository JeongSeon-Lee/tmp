/* 4. ���� �Էµ� ������ ���� 100���� n�� �Է¹ް�, �̾ n���� ������ �޾� ������� �迭�� �����Ѵ�. 
�׷� ���� Ű����� ���� �ٽ� �ϳ��� ���� k�� �Է¹��� �� n���� ������ �߿��� k�� ���� �����, ��
k���� ������ ���밪�� ���� ���� ������ ã�� ����ϴ� ���α׷��� �ۼ��϶�. */

#include <stdio.h>

int abs(int a)
{
    if (a >= 0) return a;
    return -a;
}

int main(void)
{
    int n, k;
    int num[100];
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
        scanf_s("%d", &num[i]);
    scanf_s("%d", &k);

    /* ��, �ּҰ� ���� �� ����� ����, �����͸� �� �а� ���� �����س����� �Ǵ��� */
    /* �ּ����� */

    int idx_min_diff = 0;
    for (int i = 1; i < n; i++) {
        if (abs(num[i] - k) < abs(num[idx_min_diff] - k))
            idx_min_diff = i;
    }

    printf("%d", num[idx_min_diff]);

    return 0;
}