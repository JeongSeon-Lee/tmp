/* 1. 정렬(sort)을 하는 가장 간단한 방법 중의 하나는 다음과 같이 하는 것이다. 배열 data에 data[0]에서 
data[n-1]까지 개의 정수가 저장되어 있다. 먼저 data[0] ~ data[n-1] 사이의 정수들 중에서 가
장 큰 정수를 찾는다. 그것을 data[k]라고 가정해보자. 그러면 data[k]와 data[n-1]을 교환(swap)
한다. 이제 가장 큰 정수가 data[n-1], 즉 맨 마지막 위치에 저장되었으므로 그 값에 대해서는 더 이
상 생각할 필요가 없다. 이제 data[0] ~ data[n-2] 중에서 최대값을 찾는다. 그 값을 data[p]라고 
하자. 그러면 다시 data[p]와 data[n-2]를 교환하고 data[n-2]에 대해서는 잊어버려도 된다. 이런 
식으로 계속하면 마지막에는 data[0]와 data[1] 중에 최대값을 data[1]과 교환하면 전체의 정렬이 
완료된다. 이 알고리즘을 구현하라. 입력은 먼저 정렬할 정수의 개수 이 주어지고 이어서 개
의 정수들이 주어진다. */

/* 선택 정렬 */
#include <stdio.h>

int main(void)
{
	int data[100];
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	int i, j;
	for (i = n - 1; i >= 0; i--) {
		int idx_max = 0;
		for (j = 1; j <= i; j++) {
			if (data[j] > data[idx_max]) {
				idx_max = j;
			}
		}
		if (data[i] != data[idx_max]) {
			int tmp = data[i];
			data[i] = data[idx_max];
			data[idx_max] = tmp;
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}

	return 0;
}