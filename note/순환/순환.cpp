#include <stdio.h>

// 매개변수의 명시화

int sequentialSearch(int data[], int begin, int end, int target);

int main(void) {
	int data[] = { 3, 5, 2, 10, 50, 23, 14, 39 };
	int n = sizeof(data) / sizeof(data[0]);

	printf("sequential search\n-----------------\n");
	for (int i = 0; i < n; i++) {
		printf("target index: %d\n", sequentialSearch(data, 0, n - 1, data[i]));
		printf("----------------\n");
	}

	printf("\n");
	printf("binary search\n-------------\n");
	return 0;
}

int sequentialSearch(int data[], int begin, int end, int target) {
	printf("> %d~%d: 시작\n", begin, end);
	if (begin > end) {
		printf("입뺀\n");
		return -1;
	}
	//else if (target == data[begin])
	//	return begin;
	//else 
	//	return sequentialSearch(data, begin + 1, end, target);

	//else if (target == data[end])
	//	return end;
	//else
	//	return sequentialSearch(data, begin, end - 1, target);

	else {
		int middle = (begin + end) / 2;
		printf("%d\n", middle);
		if (data[middle] == target)
			return middle;
		printf("%d~%d: sequentialSearch(%d, %d)\n", begin, end, begin, middle - 1);
		int index = sequentialSearch(data, begin, middle - 1, target);
		printf("%d~%d: %d~%d: %d\n", begin, end, begin, middle - 1, index);
		if (index != -1) {
			return index;
		}
		else {
			printf("%d~%d: sequentialSearch(%d, %d)\n",begin, end, middle+1, end);
			return sequentialSearch(data, middle + 1, end, target);
		}
	}
}

int binarySearch(int data[], int target, int begin, int end) {
	if (begin > end)
		return -1;
	else {
		int middle = (begin + end) / 2;
		if (data[middle] == target)
			return middle;
		else if (data[middle] > target)
			return binarySearch(data, target, begin, middle - 1);
		else
			return binarySearch(data, target, middle + 1, end);
	}
}