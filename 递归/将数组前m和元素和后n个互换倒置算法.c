#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(int arr[], int start, int end) {
    int i, temp;
    for (i = start; i < (start + end) / 2; i++) {
        temp = arr[i];
        arr[i] = arr[end - i + start - 1];
        arr[end - i + start - 1] = temp;
    }
}

// 倒置算法
void converse(int arr[], int m, int p) {
    reverse(arr, 0, p + m);
    reverse(arr, 0, m);
    reverse(arr, m, m + p);
}

void showArray(int arr[], int length) {
    for (size_t i = 0; i < length; i++) {
        printf("%-3d", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[5] = { 1,2,3,4,5 };
    int length = sizeof(arr) / sizeof(arr[0]);
    showArray(arr, length);
    converse(arr, 2, 3);
    showArray(arr, length);
}