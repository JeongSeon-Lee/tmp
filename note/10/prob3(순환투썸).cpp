/* 통과 완료 */
#include <stdio.h>

int count = 0;

void twoSum(int data[], int begin, int end, int k) {
	if (begin >= end)
		return;
	else {
		if (data[begin] + data[end] == k) {
			count++;
			return twoSum(data, begin + 1, end - 1, k);
		}
		else if (data[begin] + data[end] < k)
			return twoSum(data, begin + 1, end, k);
		else
			return twoSum(data, begin, end - 1, k);
	}
}

int main(void) {
	int n, k, data[1000];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &data[i]);
	scanf_s("%d", &k);
	twoSum(data, 0, n - 1, k);
	printf("%d\n", count);
	return 0;
}