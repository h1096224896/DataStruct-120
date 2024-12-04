#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void selectSort(int* arr, int len) {
    for (size_t i = 0; i < len - 1; i++) {
        for (size_t j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main() {

    return 0;
}