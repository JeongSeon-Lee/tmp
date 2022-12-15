/* 3. 입력 파일 board.txt에 오목판의 상태가 주어진다. 파일의 첫 줄에는 바둑판의 크기 19이하 n가 주어
지고, 이어진 n줄에는 각 줄마다 n개의 정수 0, 1, 혹은 2가 주어진다. 0은 빈자리를 표시하고, 1은 검
은 돌, 2는 흰 돌을 표시한다. 주어진 상태가 검은 돌이 이긴 상태인지, 흰 돌이 이긴 상태인지, 혹은 아
직 아무도 못 이긴 상태인지 검사하여 Black, White, 혹은 Not Finished라고 출력하는 프로그램을
작성하라. 둘 다 이긴 상태는 없다고 가정한다. 참고로 오목 게임은 내 돌이 수평, 수직, 혹은 대각선 방
향으로 연속해서 5개가 놓이면 이기는 게임이다. */

#include <stdio.h>
#include <string.h>
#define MAX 100

int N;
int board[MAX][MAX];

bool check(int x, int y);

int main(void)
{
    FILE* fp = 0;
    fopen_s(&fp, "board.txt", "r");
    fscanf_s(fp, "%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf_s(fp, "%d", &board[i][j]);
        }
    }
    fclose(fp);

    // 항상 끝점을 먼저 만남
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0)
                continue;
            // check if board[i][j] is an end of 5-consective stone of same color
            if (check(i, j)) {
                if (board[i][j] == 1)
                    printf("black");
                else
                    printf("white");
                return 0;
            }
        }
    }
    printf("not finished");
    return 0;
}

// 4방향, xy 증가
int offset[4][2] = { {1, -1},
                    {1, 0},
                    {1, 1},
                    {0, 1} };
bool check(int x, int y) {
    // check four directions, SW, S, SE, E
    int mystone = board[x][y];
    for (int dir = 0; dir < 4; dir++) {
        int d = 1;
        while (d < 5 && x + d * offset[dir][0] < N
            && y + d * offset[dir][1] >= 0
            && y + d * offset[dir][1] < N) {
            if (board[x + d * offset[dir][0]][y + d * offset[dir][1]] != mystone)
                break;
            d++;
        }
        if (d == 5)
            return true;
    }
        int d = 1;
        while (d < 5 && x + d < N && y - d >= 0) {
            if (board[x + d][y - d] != mystone)
                break;
            d++;
        }
        if (d == 5)
            return true;

        int d = 1;
        while (d < 5 && x + d < N) {
            if (board[x + d][y] != mystone)
                break;
            d++;
        }
        if (d == 5)
            return true;

        return false;

        int d = 1;
        while (d < 5 && x + d < N && y + d < N) {
            if (board[x + d][y + d] != mystone)
                break;
            d++;
        }
        if (d == 5)
            return true;

        return false;

        int d = 1;
        while (d < 5 && y + d < N) {
            if (board[x][y + d] != mystone)
                break;
            d++;
        }
        if (d == 5)
            return true; 

    return false;
}

/* 오른쪽 */
if (j <= n - 5
    && board[i][j] == board[i][j + 1]
    && board[i][j + 1] == board[i][j + 2]
    && board[i][j + 2] == board[i][j + 3]
    && board[i][j + 3] == board[i][j + 4])
/* 오른쪽 아래*/
else if (i <= n - 5 && j <= n - 5
    && board[i][j] == board[i + 1][j + 1]
    && board[i + 1][j + 1] == board[i + 2][j + 2]
    && board[i + 2][j + 2] == board[i + 3][j + 3]
    && board[i + 3][j + 3] == board[i + 4][j + 4])
/* 아래 */
else if (i <= n - 5
    && board[i][j] == board[i + 1][j]
    && board[i + 1][j] == board[i + 2][j]
    && board[i + 2][j] == board[i + 3][j]
    && board[i + 3][j] == board[i + 4][j])
/* 왼쪽 아래*/
else if (i <= n - 5 && j >= 4
    && board[i][j] == board[i + 1][j - 1]
    && board[i + 1][j - 1] == board[i + 2][j - 2]
    && board[i + 2][j - 2] == board[i + 3][j - 3]
    && board[i + 3][j - 3] == board[i + 4][j - 4])