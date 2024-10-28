#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 希尔排序
// 平均:O(n^1.3) 最好:O(n) 最坏:O(n^2)
void shellSort(int* arr, int len) {
    for (int gap = len / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < len; i++) {
            int temp = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > temp) {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = temp;
        }
    }
}



int main() {
    system("pause");
    return 0;
}