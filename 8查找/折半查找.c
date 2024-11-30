#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 二分查找
int binSearch(int arr[], int size, int num) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == num)
            return 1;
        if (arr[mid] < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}



int main() {
    int arr[] = {10,20};
    int len = sizeof(arr) / sizeof(arr[0]);
    if (binSearch(arr, len, 20)) {
        printf("找到该元素.\n");
    }
    else {
        printf("未找到该元素。\n");
    }
    return 0;
}