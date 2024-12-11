#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 编写函数:希尔排序,并打印每趟排序结果
void ShellSort(int A[], int n) {
    int i, j, gap;
    int temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = A[i];
            for (j = i - gap; j >= 0 && A[j] > temp; j -= gap) {
                A[j + gap] = A[j];
            }
            A[j + gap] = temp;
        }
        for (int k = 0; k < n; k++) {
            printf("%d ", A[k]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[] = { 54, 43,70,102,81,18,32,55,60,9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    ShellSort(arr, n);
    return 0;
}