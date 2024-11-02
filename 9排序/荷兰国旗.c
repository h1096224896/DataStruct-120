#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void FlagNetherlands(int* arr, int len) {
    int low = 0, mid = 0, high = len - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

int main() {
    int arr[12] = { 1,0,2,0,2,0,1,1,0,2,0,0 };
    int len = sizeof(arr) / sizeof(arr[0]);
    FlagNetherlands(arr, len);
    for (size_t i = 0; i < len; i++) {
        printf("%-3d", arr[i]);
    }
    return 0;
}