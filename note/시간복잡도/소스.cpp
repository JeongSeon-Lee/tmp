// 이진검색 : O(logn)
int binarySearch(int n, char* data[], char* target) {
	int begin = 0, end = n - 1;
	while (begin <= end) {
		int middle = (begin + end) / 2;
		int result = strcmp(data[middle], target);
		if (result == 0)
			return middle;
		else if (result < 0)
			begin = middle + 1;
		else
			end = middle - 1;
	}
	return -1;
}

// 버블정렬 : O(n2), 그림을 생각해보소
void bubbleSort(int data[], int n) {
	for (int i = n - 1; i > 0; i--) {	// 맨 뒤 고정
		for (int j = 0; j < i; j++) {
			if (data[j] > data[j + 1]) {	// i - 1 vs i
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}

// 삽입정렬 : 최선 O(n), 최악 O(n2)
void insertionSort(int n, int data[]) {
	for (int i = 1; i < n; i++) {	// i = 0은 이미 정렬된 상태로 봄
		int tmp = data[i];
		int j = i - 1;
		while (j >= 0 && data[j] > tmp) {
			data[j + 1] = data[j];	// 한 칸씩 비교
			j--;
		}
		data[j + 1] = tmp;	// j가 -1일 때나 tmp가 이전 것보다 클 때 
	}
}