/* 2. 먼저 입력될 정수의 개수 2이상 100이하 n을 입력받고, 이어서 개의 정수를 입력받는다. 입력된 정수들 중
에서 최소값과 두번째로 작은 값을 찾아 출력하는 프로그램을 작성하라. 만약 최소값이 2개 이상 중복
되어 존재하면 그 중 하나를 최소값으로, 다른 하나를 두 번째로 작은 값으로 간주한다. */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int num[100];  /* 배열의 길이를 변수로 지정 할 수 없음, 혹은 동적 메모리 할당,
    현재 문제에선 100이니까, 100에서는 메모리 소비가 적음, 상업적일 때는 신경 써봐야 함 */
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &num[i]);
    }

    /* 최솟값은 아주아주아주 기본적인 로직, 생각하지 않고 쓸 정도 */
    int theMin;
    int theSecond;
    if (num[0] <= num[1]) {
        theMin = num[0];
        theSecond = num[1];
    }
    else {
        theMin = num[1];
        theSecond = num[0];
    }
    for (int i = 2; i < n; i++) {
        if (num[i] <= theMin) {     // =
            theSecond = theMin;     // 이전 최소값을 세컨값으로 둠
            theMin = num[i];
        }
        else if (num[i] < theSecond) {  // theSecond > num[i] > theMin
            theSecond = num[i];
        }
    }
    printf("%d %d\n", theMin, theSecond);
    return 0;
}