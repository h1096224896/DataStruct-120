#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fun(int* arr, int base, int len) {
    int low = 0;
    int high = len - 1;
    int temp = arr[0];
    while (low < high) {
        while (arr[high] >= base && low < high)
            high--;
        if (low < high)
            arr[low++] = arr[high];
        while (arr[low] <= base && low < high)
            low++;
        if (low < high)
            arr[high--] = arr[low];
    }
    arr[low] = temp;
}

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < 10; i++) {
        printf("%-3d", *(arr + i));
    }
    int base;
    printf("请输入比较基准:");
    scanf("%d", &base);
    fun(arr, base, 10);
    for (int i = 0; i < 10; i++) {
        printf("%-3d", *(arr + i));
    }
    return 0;
}