/* 3. Ű����� ���� �����ؼ� ���� �ƴ� �������� �Է¹޴´�. ������ �ϳ� �� �Էµ� �� ���� ������� ��
�µ� �������� ������������ �����Ͽ� ȭ�鿡 ����Ѵ�. ��, ���� �Էµ� ������ �̹� ������ �Էµ�
������� ��duplicate����� ����ϰ� �������� �ʰ� ������. ����ڰ� -1�� �Է��ϸ� ���α׷��� ��
���Ѵ�. �ԷµǴ� ������ ������ 100���� ���� �ʴ´�. */

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

        /* ������ �迭�� ������������ ���ĵǾ� �ֱ⿡ �Է°��� ������� �񱳸� �ϴٰ�
        �Է°����� ū ���� ������ ��� �� �ڴ� �˻��� �ʿ䰡 ���� */
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

/* �Ű����� �ϳ��� ������ �����ϱ� ��ȯ������ ������ */
int insert(int n, int num[], int k)
{
    /* ������ �迭�� ������������ ���ĵǾ� �ֱ⿡ �Է°��� ������� �񱳸� �ϴٰ�
    �Է°����� ū ���� ������ ��� �� �ڴ� �˻��� �ʿ䰡 ���� */
    int i = 0;
    for (; i < n && num[i] <= k; i++) {
        if (num[i] == k) {
            printf("duplicate\n");
            return n;
        }
    }
    /* �Է°��� ���� �� �ڸ��� �� */
    /* i�� n�� �� ���� ū �����̰ų�  */

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