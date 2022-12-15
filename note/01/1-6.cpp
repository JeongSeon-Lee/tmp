/* 6. 주사위를 번 던져서 1이 적어도 번 나오는 확률을 실험적으로 계산하는 함수
 double prob(int N, int k)
를 작성하라. 이 함수에서는 주사위를 k번 던져서 그 중 1이 번 이상 나오는지는 검사하는 실험을
1,000,000번 반복한다. 이 1,000,000번의 실험 중에서 1이 번 이상 나온 횟수를 카운트하여 확률을
실험적으로 추정한다. 이 함수를 이용하여“k = 1,2, ,,, 6에 대해서 주사위를 6k번 던져서 1이 k번 이
상 나올 확률”이 각각 어떻게 되는지 계산하여 출력하는 프로그램을 작성하라. 6번 던져서 1이 1번 이
상 나오는 사건의 확률은 1-(5/6)6 ≃ 0.6651이고, 12번 중 적어도 2번 1이 나오는 사건의 확률은 1-
(5/6)12-2(5/6)11 ≃ 0.618667이다. 이 두 경우에 대해서 대략 이 확률에 근접하는 결과가 나오면 정답
이다. 참고로 C언어에서 랜덤 정수는 다음의 예에서와 같이 생성한다 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double prob(int N, int k);

int main(void)
{
    srand((unsigned int)time(NULL));

    for (int k = 1; k <= 6; k++) {
        double p = prob(6 * k, k);
        printf("%lf\n", p);
    }

    return 0;
}

double prob(int N, int k)
{
    int num_sucess = 0;
    for (int e = 0; e < 1000000; e++) {
        int count_one = 0;
        for (int t = 0; t < N; t++) {
            int r = rand() % 6 + 1;
            if (r == 1)
                count_one++;
        }
        if (count_one >= k)
            num_sucess++;
    }

    return (double)num_sucess / 1000000;
}