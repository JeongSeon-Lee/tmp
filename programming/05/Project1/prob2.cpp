/* 통과 완료 */
#include <stdio.h>
#include <string.h>

void show();
void colmax();
void colmin();
void rowmax();
void rowmin();
void slice(int x, int p, int y, int q);

int data[100][100];
int n;

int main(void)
{
	FILE* fp = 0;
	fopen_s(&fp, "data.mat", "r");
	if (fp == NULL) {
		printf("����");
	}
	fscanf_s(fp, "%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf_s(fp, "%d", &data[i][j]);
		}
	}
	fclose(fp);

	while (1) {
		char command[50];
		printf("$ ");
		scanf_s("%s", command, 50);
		if (strcmp(command, "show") == 0)
			show();
		else if (strcmp(command, "colmax") == 0)
			colmax();
		else if (strcmp(command, "colmin") == 0)
			colmin();
		else if (strcmp(command, "rowmax") == 0)
			rowmax();
		else if (strcmp(command, "rowmin") == 0)
			rowmin();
		else if (strcmp(command, "slice") == 0) {
			int x, p, y, q;
			scanf_s("%d%d%d%d", &x, &p, &y, &q);
			slice(x, p, y, q);
		}
		else if (strcmp(command, "exit") == 0)
			break;
	}

	return 0;
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%2d ", data[i][j]);
		}
		printf("\n");
	}
}

void colmax() {
	for (int j = 0; j < n; j++) {
		int max = data[0][j];
		for (int i = 0; i < n; i++) {
			if (max < data[i][j])
				max = data[i][j];
		}
		printf("%2d ", max);
	}
	printf("\n");
}

void colmin() {
	for (int j = 0; j < n; j++) {
		int min = data[0][j];
		for (int i = 0; i < n; i++) {
			if (min > data[i][j])
				min = data[i][j];
		}
		printf("%2d ", min);
	}
	printf("\n");
}

void rowmax() {
	for (int i = 0; i < n; i++) {
		int max = data[i][0];
		for (int j = 0; j < n; j++) {
			if (max < data[i][j])
				max = data[i][j];
		}
		printf("%2d ", max);
	}
	printf("\n");
}

void rowmin() {
	for (int i = 0; i < n; i++) {
		int min = data[i][0];
		for (int j = 0; j < n; j++) {
			if (min > data[i][j])
				min = data[i][j];
		}
		printf("%2d ", min);
	}
	printf("\n");
}

void slice(int x, int p, int y, int q) {
	for (int i = x; i < n; i += p) {
		for (int j = y; j < n; j += q) {
			printf("%2d ", data[i][j]);
		}
		printf("\n");
	}
}