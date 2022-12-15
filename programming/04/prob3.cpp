#include <stdio.h>
#include <string.h>

int main(void)
{
	int m, n;
	char * table[10][10];
	FILE * fp = fopen("04/table.txt", "r");
	fscanf(fp, "%d%d", &m, &n);
	char buf[100];
	fgets(buf, 100, fp);
	
/* 	printf("%d %d\n", m, n);
	char buf[100];
	fgets(buf, 100, fp);
	printf("%s", buf);
	fgets(buf, 100, fp);
	printf("%s", buf);
	table[0][0] = strtok(buf, "&");
	printf("%s|", table[0][0]);
	table[0][1] = strtok(NULL, "&");
	printf("%s|", table[0][1]);
	printf("%s|", table[0][0]); */
/* 	table[0][0] = strtok(buf, "&");
	printf("%s", table[0][0]); */

	for (int i = 0; i < m; i++) {
		char buf[100];
		fgets(buf, 100, fp);
		table[i][0] = strtok(buf, "&");
		for (int j = 1; j < n; j++) {
			table[i][j] = strtok(NULL, "&");
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%s|", table[i][j]);
		}
		printf("\n");
	}

}