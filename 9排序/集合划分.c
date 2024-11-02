#include <stdio.h>
#include <stdlib.h>

void partitionSet(int A[], int n, int A1[], int* n1, int A2[], int* n2) {
    int sum1 = 0, sum2 = 0;
    *n1 = 0;  // A1 中的元素数量
    *n2 = 0;  // A2 中的元素数量

    for (int i = 0; i < n; i++) {
        // 如果 A1 的和小于等于 A2，且 A1 的元素个数不超过总元素个数的一半
        if (sum1 <= sum2 && *n1 < (n + 1) / 2) {
            A1[*n1] = A[i];
            sum1 += A[i];
            (*n1)++;
        }
        else {  // 否则，将元素加入 A2
            A2[*n2] = A[i];
            sum2 += A[i];
            (*n2)++;
        }
    }
}

int main() {
    int A[] = {1,2,3,4,5};  // 示例输入数组
    int n = sizeof(A) / sizeof(A[0]);

    int A1[n], A2[n];  // 定义两个数组来存储 A1 和 A2
    int n1 = 0, n2 = 0;  // A1 和 A2 的元素个数

    // 划分集合
    partitionSet(A, n, A1, &n1, A2, &n2);

    // 输出结果
    printf("Subset A1: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", A1[i]);
    }
    printf("\nSubset A2: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", A2[i]);
    }
    printf("\n");

    return 0;
}