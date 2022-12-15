/* 2. �Է����� 100�� �̸� n���� ����(interval)�� �־�����. �� ������ ������ �������� �������� ǥ���ȴ�. ��
�������� �������� ���� ������� �����Ͽ� ����ϴ� ���α׷��� �ۼ��϶�. �������� ���� ��� ����
�� ���� ���� ���� ����Ѵ�. �Է� ������ ���� n�� ���� �־�����, �̾ �� ������ �������� ������
���ʴ�� �־�����. �� ������ �������� ������ �����̰�, ������ �׻� ���������� ũ�ų� ����. */

#include <stdio.h>

int main(void)
{
	int n;
	scanf_s("%d", &n);
	int start[100], end[100];
	for (int i = 0; i < n; i++) {
		scanf_s("%d%d", &start[i], &end[i]);
	}

	int i, j;
	for (i = n - 1; i >= 0; i--) {
		int idx_max = 0;
		for (j = 1; j <= i; j++) {
			if (start[j] > start[idx_max] || start[j] == start[idx_max] && end[j] > end[idx_max]) {
				idx_max = j;
			}
		}
		int tmp = start[i];
		start[i] = start[idx_max];
		start[idx_max] = tmp;

		tmp = end[i];
		end[i] = end[idx_max];
		end[idx_max] = tmp;
	}

	for (i = 0; i < n; i++) {
		printf("%d %d\n", start[i], end[i]);
	}

	return 0;
}

//void bubblesort(int n, int num1[], int num2[])
//{
//	int tmp;
//	for (int i = n - 1; i > 0; i--) {
//		for (int j = 0; j < i; j++) {
//			if (num1[j] > num1[j + 1] || num1[j] == num1[j + 1] && num2[j] > num2[j + 1]) {
//				if (num1[j] != num1[j + 1]) {
//					tmp = num1[j];
//					num1[j] = num1[j + 1];
//					num1[j + 1] = tmp;
//				}
//				tmp = num2[j];
//				num2[j] = num2[j + 1];
//				num2[j + 1] = tmp;
//			}
//		}
//	}
//}