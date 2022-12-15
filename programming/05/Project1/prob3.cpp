/* 통과 완료 */
#include <stdio.h>

int board[20][20];
int n;

int main(void)
{
	FILE* fp = 0;
	fopen_s(&fp, "board.txt", "r");
	fscanf_s(fp, "%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf_s(fp, "%d", &board[i][j]);
		}
	}
	fclose(fp);

	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (board[i][j] != 0) {
				/* ?????? */
				if (j <= n - 5
					&& board[i][j] == board[i][j + 1] 
					&& board[i][j + 1] == board[i][j + 2] 
					&& board[i][j + 2] == board[i][j + 3]
					&& board[i][j + 3] == board[i][j + 4]) {
					if (board[i][j] == 1)
						printf("Black\n");
					else
						printf("White\n");
					i = n + 1;
					break;
				}
				/* ?????? ???*/
				else if (i <= n - 5 && j <= n - 5
					&& board[i][j] == board[i + 1][j + 1]
					&& board[i + 1][j + 1] == board[i + 2][j + 2]
					&& board[i + 2][j + 2] == board[i + 3][j + 3]
					&& board[i + 3][j + 3] == board[i + 4][j + 4]) {
					if (board[i][j] == 1)
						printf("Black\n");
					else
						printf("White\n");
					i = n + 1;
					break;
				}
				/* ??? */
				else if (i <= n - 5
					&& board[i][j] == board[i + 1][j]
					&& board[i + 1][j] == board[i + 2][j]
					&& board[i + 2][j] == board[i + 3][j]
					&& board[i + 3][j] == board[i + 4][j]) {
					if (board[i][j] == 1)
						printf("Black\n");
					else
						printf("White\n");
					i = n + 1;
					break;
				}
				/* ???? ???*/
				else if (i <= n - 5 && j >= 4
					&& board[i][j] == board[i + 1][j - 1]
					&& board[i + 1][j - 1] == board[i + 2][j - 2]
					&& board[i + 2][j - 2] == board[i + 3][j - 3]
					&& board[i + 3][j - 3] == board[i + 4][j - 4]) {
					if (board[i][j] == 1)
						printf("Black\n");
					else
						printf("White\n");
					i = n + 1;
					break;
				}
			}
		}
	}
	if (i == n)
		printf("Not Finished\n");

	return 0;
}