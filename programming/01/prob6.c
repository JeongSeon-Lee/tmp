/* 통과 완료 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double prob(int N, int k)
{
    int i;
    double ans = 0.0;
    int n = N;

    for (i = 0; i < k; i++) {
        ans += factorial(N) / factorial(n) * pow(0.166667, i) * pow(0.833333, n);
        n--;
    }

    return (1 - ans);
}

int factorial(int n)
{
    if (n == 1)
        return 1;

    return n * factorial(n - 1);
}

int main(void)
{
    srand((unsigned int)time(NULL));
    int k = rand() % 6 + 1;
    
    printf("%lf", prob(6 * k, k));

    return 0;
}