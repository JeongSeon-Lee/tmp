/* 통과 완료 */
#include <stdio.h>

// void insert(int *n, int num[], int k);
int insert(int n, int num[], int k);

int main(void)
{
    /* 전역변수를 남발하지 마라. 는 규모가 클 때 일부분에서 그 변수를 사용할 경우
    현재 프로그램에서는 모든 부분에서 쓰이므로 오히려 더 단순화되고 사용했을 때 좋음 */
    int num[100];
    int n = 0, k;

    /* -1를 입력할 때 끝이 나므로 while */
    while (1) {
        scanf("%d", &k);
        if (k==-1) break;
        /* 아래는 k를 처리하는 부분,
        main 함수에서 모든 일을 하는 것은 좋지 않음, 길어질 뿐더러 가독성 떨어짐 */
        // insert(&n, num, k);
        n = insert(n, num, k);
        // bool duplicate = false;
        // for (int i=0; i<n; i++) {
        //     if (num[i] == k) {
        //         printf("duplicate\n");
        //         duplicate = true;
        //         break;
        //     }
        // }
        // /* k가 중복된 값인지 알 수 있어야 함 */
        // /* 이미 정렬이 되어 있는 상태에서 추가하여 정렬 => 삽입 정렬 */
        // if (!duplicate) {
        //     int j = n-1;
        //     while (j>=0 && num[j] > k) {    /* j>=0 &&는 초보 때 금방금방 안 떠오름
        //                                         처음 조건 불만족 또는 두번째 조건 불만족으로 빠져나옴 */
        //         num[j+1] = num[j];
        //         j--;
        //     }
        //     num[j+1] = k;   //
        //     n++;    //

        //     for (int i=0; i<n; i++)
        //         printf("%d ", num[i]);
        //     printf("\n");
        // }
    }

    return 0;
}

// void insert(int *n, int num[], int k)
// {
//     for (int i=0; i<*n; i++) {
//         if (num[i] == k) {
//             printf("duplicate\n");
//             return;
//         }
//     }
//     /* 앞에서 중복이면 함수를 끝내기 때문에 아래에서는 중복이 아닌 경우에만 실행 됨 */
//     int j = *n-1;
//     while (j>=0 && num[j] > k) {
//         num[j+1] = num[j];
//         j--;
//     }
//     num[j+1] = k;   //
//     (*n)++;    //      /* 값에 의한 호출, main n의 값이 바뀌지 않음 */
//     /* 전역변수로 보내기 또는 변수의 주소를 넘겨줌 */

//     for (int i=0; i<*n; i++)
//         printf("%d ", num[i]);
//     printf("\n");
// }

/* 매개변수 하나만 문제가 있으니까 반환값으로 내보냄 */
int insert(int n, int num[], int k)
{
    /* 어차피 배열은 오름차순으로 정렬되어 있기에 입력값을 순서대로 비교를 하다가 
    입력값보다 큰 수가 나왔을 경우 그 뒤는 검사할 필요가 없음 */
    int i=0;
    for (; i<n && num[i] <= k; i++) {
        if (num[i] == k) {
            printf("duplicate\n");
            return n;
        }
    }
    /* 입력값이 들어가야 할 자리를 앎 */
    /* i가 n일 때 가장 큰 정수이거나  */

    // i --> position to insert

    int j = n-1;
    for (; j>=i; j--)
        num[j+1] = num[j];
    num[j+1] = k;   //
    n++;    //      /* 값에 의한 호출, main n의 값이 바뀌지 않음 */
    /* 전역변수로 보내기 또는 변수의 주소를 넘겨줌 */

    for (i=0; i<n; i++)
        printf("%d ", num[i]);
    printf("\n");

    return n;
}