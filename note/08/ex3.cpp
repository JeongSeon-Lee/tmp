/* 통과 완료 */
#include <stdio.h>
#include <time.h>

int t;
int data[1000000];
int stack[1000000];
int top = -1;

void push(int item) {
	++top;
	stack[top] = item;
}

int pop() {
	top--;
	return stack[top + 1];
}

bool is_empty() {
	return top == -1;
}

int peek() {
	return stack[top];
}

void clear_stack() {
	top = -1;
}

void pop_less_than(int val) {
	while (!is_empty() && data[peek()] <= val)
		pop();
}

int main(void)
{
	clock_t start, end;
	start = clock();

	FILE* fp = 0;
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL)
		printf("파일 열기 실패");

	int n;
	fscanf_s(fp, "%d", &t);
	for (int i = 0; i < t; i++) {
		int idx = 0;
		int sum = 0;	// unsigned long long
		fscanf_s(fp, "%d", &n);
		for (int j = 0; j < n; j++) {
			fscanf_s(fp, "%d", &data[j]);
			pop_less_than(data[j]);		// bool min = true;
			//for (int k = 0; k < idx; k++) {
			//	if (data[stack[k]] <= data[j]) {
			//		stack[k] = j;
			//		int tmp = idx;
			//		idx = k + 1;
			//		min = false;
			//		break;
			//	}
			//}
			//if (min)
			//	stack[idx++] = j;
			//result += idx == 1 ? stack[idx - 1] : (stack[idx - 1] - stack[idx - 2] - 1);
			if (is_empty())
				sum = (sum +j) % 1000000;
			else
				sum = (sum + j - peek() - 1) % 1000000;
			push(j);
		}
		printf("%d\n", sum);
		clear_stack();

	}
	fclose(fp);

	end = clock();
	printf("Elapsed Time : %f\n", (float)(end - start) / CLOCKS_PER_SEC);

	return 0;
}