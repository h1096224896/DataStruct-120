#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 折半插入排序
// 平均:O(n^2) 最好(正序):O(n) 最坏(逆序):O(n^2)
void insertHalfsortort(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        int temp = arr[i];  // 保存当前值
        int low = 0, high = i - 1;
        while (low <= high) {  // 找插入位置
            int mid = (low + high) / 2;
            if (temp > arr[mid]) {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        for (int j = i - 1; j > low; j--) {
            arr[j + 1] = arr[j];
        }
        arr[low] = temp;
    }

}

int main() {
    int arr[] = { 23, 12, 45, 2,2, 67, 34, 89, 12, 34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    insertHalfsortort(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

// { 23, 12, 45, 2,  2,  67, 34, 89, 12, 34 }
// { 12, 23, 45, 2,  2,  67, 34, 89, 12, 34 }
// { 12, 23, 45, 2,  2,  67, 34, 89, 12, 34 }
// { 2,  2,  12, 12, 23, 34, 34, 45, 67, 89 }
