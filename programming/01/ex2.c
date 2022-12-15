/* 통과 완료 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int num[100];  /* 배열의 길이를 변수로 지정 할 수 없음, 혹은 동적 메모리 할당, 
    현재 문제에선 100이니까, 100에서는 메모리 소비가 적음, 상업적일 때는 신경 써봐야 함 */
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &num[i]);
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
    for (int i=2; i<n; i++) {
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