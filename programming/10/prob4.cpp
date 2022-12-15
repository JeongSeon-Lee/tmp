/* 통과 완료 */
#include <stdio.h>

int floor(int data[], int index, int idx_end, int k) {
	if (index > idx_end) {
		return -1;
	}
	else {
		if (data[index] < k) {
			int result = floor(data, index + 1, idx_end, k);
			if (result == -1)
				return data[index];
			else
				return result;
		}
		else if (data[index] == k)
			return data[index];
		else
			return -1;
	}
}

int ceiling(int data[], int index, int idx_end, int k) {
	if (index > idx_end)
		return -1;
	else {
		if (data[index] < k) {
			return ceiling(data, index + 1, idx_end, k);
		}
		else
			return data[index];
	}
}


int main(void) {
	int n, k, data[1000];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &data[i]);
	scanf_s("%d", &k);
	printf("%d\n%d\n", floor(data, 0, n - 1, k), ceiling(data, 0, n - 1, k));
	return 0;
}