// �����˻� : O(logn)
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

// �������� : O(n2), �׸��� �����غ���
void bubbleSort(int data[], int n) {
	for (int i = n - 1; i > 0; i--) {	// �� �� ����
		for (int j = 0; j < i; j++) {
			if (data[j] > data[j + 1]) {	// i - 1 vs i
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}

// �������� : �ּ� O(n), �־� O(n2)
void insertionSort(int n, int data[]) {
	for (int i = 1; i < n; i++) {	// i = 0�� �̹� ���ĵ� ���·� ��
		int tmp = data[i];
		int j = i - 1;
		while (j >= 0 && data[j] > tmp) {
			data[j + 1] = data[j];	// �� ĭ�� ��
			j--;
		}
		data[j + 1] = tmp;	// j�� -1�� ���� tmp�� ���� �ͺ��� Ŭ �� 
	}
}