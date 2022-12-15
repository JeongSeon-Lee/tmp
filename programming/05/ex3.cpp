#include <stdio.h>
#include <string.h>
#define MAX 100

int N;
int board[MAX][MAX];

bool check(int x, int y);

int main(void)
{
    FILE *fp = fopen("board.txt", "r");
    fscanf(fp, "%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d", &board[i][j]);
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
int offset[4][2] = {{1, -1},
                    {1, 0},
                    {1, 1},
                    {0, 1}};
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
/*     int d = 1;
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
        return true; */
    
    return false;
}