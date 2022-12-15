/* 3. �Է� ���� board.txt�� �������� ���°� �־�����. ������ ù �ٿ��� �ٵ����� ũ�� 19���� n�� �־�
����, �̾��� n�ٿ��� �� �ٸ��� n���� ���� 0, 1, Ȥ�� 2�� �־�����. 0�� ���ڸ��� ǥ���ϰ�, 1�� ��
�� ��, 2�� �� ���� ǥ���Ѵ�. �־��� ���°� ���� ���� �̱� ��������, �� ���� �̱� ��������, Ȥ�� ��
�� �ƹ��� �� �̱� �������� �˻��Ͽ� Black, White, Ȥ�� Not Finished��� ����ϴ� ���α׷���
�ۼ��϶�. �� �� �̱� ���´� ���ٰ� �����Ѵ�. ����� ���� ������ �� ���� ����, ����, Ȥ�� �밢�� ��
������ �����ؼ� 5���� ���̸� �̱�� �����̴�. */

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

    // �׻� ������ ���� ����
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

// 4����, xy ����
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

/* ������ */
if (j <= n - 5
    && board[i][j] == board[i][j + 1]
    && board[i][j + 1] == board[i][j + 2]
    && board[i][j + 2] == board[i][j + 3]
    && board[i][j + 3] == board[i][j + 4])
/* ������ �Ʒ�*/
else if (i <= n - 5 && j <= n - 5
    && board[i][j] == board[i + 1][j + 1]
    && board[i + 1][j + 1] == board[i + 2][j + 2]
    && board[i + 2][j + 2] == board[i + 3][j + 3]
    && board[i + 3][j + 3] == board[i + 4][j + 4])
/* �Ʒ� */
else if (i <= n - 5
    && board[i][j] == board[i + 1][j]
    && board[i + 1][j] == board[i + 2][j]
    && board[i + 2][j] == board[i + 3][j]
    && board[i + 3][j] == board[i + 4][j])
/* ���� �Ʒ�*/
else if (i <= n - 5 && j >= 4
    && board[i][j] == board[i + 1][j - 1]
    && board[i + 1][j - 1] == board[i + 2][j - 2]
    && board[i + 2][j - 2] == board[i + 3][j - 3]
    && board[i + 3][j - 3] == board[i + 4][j - 4])