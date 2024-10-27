#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 二分查找
int binSearch(int arr[], int size, int num) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == num) {
            return 1;
        }
        else if (arr[mid] < num) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}

int main() {
    int arr[] = { -10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13 };
    int len = sizeof(arr) / sizeof(arr[0]);
    if (binSearch(arr, len, 2)) {
        printf("The element is found.\n");
    }
    else {
        printf("The element is not found.\n");
    }
    return 0;
}