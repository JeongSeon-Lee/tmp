/* 통과 완료 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 프로그래머는 코딩하기 전에 문해력이 필요 */

double prob(int N, int k);

int main(void)
{
    srand((unsigned int)time(NULL));

    for (int k=1; k<=6; k++) {
        double p = prob(6 * k, k);
        printf("%lf\n", p);
    }

    return 0;
}

double prob(int N, int k)
{
    int num_sucess = 0;
    for (int e=0; e<1000000; e++) {
        int count_one = 0;
        for (int t=0; t<N; t++) {
            int r = rand()%6 + 1;
            if (r == 1)
                count_one++;
        }
        if (count_one >= k)
            num_sucess++;
    }

    return (double)num_sucess/1000000;
}