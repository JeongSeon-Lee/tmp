/* 3. 키보드로 부터 연속해서 음이 아닌 정수들을 입력받는다. 정수가 하나 씩 입력될 때 마다 현재까지 입
력된 정수들을 오름차순으로 정렬하여 화면에 출력한다. 단, 새로 입력된 정수가 이미 이전에 입력된
정수라면 “duplicate”라고 출력하고 저장하지 않고 버린다. 사용자가 -1을 입력하면 프로그램을 종
료한다. 입력되는 정수의 개수는 100개를 넘지 않는다. */

#include <stdio.h>

// void insert(int *n, int num[], int k);
int insert(int n, int num[], int k);

int main(void)
{
    int num[100];
    int n = 0, k;

    while (1) {
        scanf_s("%d", &k);
        if (k == -1) break;
        // insert(&n, num, k);
        // n = insert(n, num, k);

        //bool duplicate = false;
        //for (int i=0; i<n; i++) {
        //    if (num[i] == k) {
        //        printf("duplicate\n");
        //        duplicate = true;
        //        break;
        //    }
        //}
        //if (!duplicate) {
        //    int j = n-1;
        //    while (j>=0 && num[j] > k) {
        //        num[j+1] = num[j];
        //        j--;
        //    }
        //    num[j+1] = k;
        //    n++;
        //    for (int i=0; i<n; i++)
        //        printf("%d ", num[i]);
        //    printf("\n");
        //}

        /* 어차피 배열은 오름차순으로 정렬되어 있기에 입력값을 순서대로 비교를 하다가
        입력값보다 큰 수가 나왔을 경우 그 뒤는 검사할 필요가 없음 */
        bool duplicate = false;
        int i = 0;
        for (; i < n && num[i] <= k; i++) {
            if (num[i] == k) {
                printf("duplicate\n");
                duplicate = true;
                break;
            }
        }
        // i --> position to insert
        // i == n || num[i] > k
        if (!duplicate) {
            int j = n - 1;
            for (; j >= i; j--)
                num[j + 1] = num[j];
            num[j + 1] = k;
            n++;
            for (i = 0; i < n; i++)
                printf("%d ", num[i]);
            printf("\n");
        }
    }

    return 0;
}

//void insert(int *n, int num[], int k)
//{
//    for (int i=0; i<*n; i++) {
//        if (num[i] == k) {
//            printf("duplicate\n");
//            return;
//        }
//    }
//    int j = *n-1;
//    while (j>=0 && num[j] > k) {
//        num[j+1] = num[j];
//        j--;
//    }
//    num[j+1] = k;
//    (*n)++;
//    for (int i=0; i<*n; i++)
//        printf("%d ", num[i]);
//    printf("\n");
//}

/* 매개변수 하나만 문제가 있으니까 반환값으로 내보냄 */
int insert(int n, int num[], int k)
{
    /* 어차피 배열은 오름차순으로 정렬되어 있기에 입력값을 순서대로 비교를 하다가
    입력값보다 큰 수가 나왔을 경우 그 뒤는 검사할 필요가 없음 */
    int i = 0;
    for (; i < n && num[i] <= k; i++) {
        if (num[i] == k) {
            printf("duplicate\n");
            return n;
        }
    }
    /* 입력값이 들어가야 할 자리를 앎 */
    /* i가 n일 때 가장 큰 정수이거나  */

    // i --> position to insert

    int j = n - 1;
    for (; j >= i; j--)
        num[j + 1] = num[j];
    num[j + 1] = k;
    n++;
    for (i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");

    return n;
}