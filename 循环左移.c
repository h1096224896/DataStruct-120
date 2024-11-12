#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fun(int* arr, int len, int n) {
    for (int i = 0; i < n; i++) {
        int temp = arr[0];
        int j = 0;
        for (j = 0; j < len - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[j] = temp;
    }
}




int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    fun(arr, 5, 4);
    for (size_t i = 0; i < 5; i++)
    {
        printf("%-3d", arr[i]);
    }
    
    return 0;
}