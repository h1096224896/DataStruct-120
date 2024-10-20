#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int merge(int arr1[], int len1, int arr2[], int len2, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
            if (k == 5)
                break;
        }
        else {
            arr3[k++] = arr2[j++];
            if (k == 5) {
                break;
            }
        }
    }
    int res = arr3[k-1];
    return res;
}

int main() {
    int arr1[5] = { 1,3,5,7,9 };
    int arr2[5] = { 2,4,6,8,10 };
    int arr3[10];
    int a = merge(arr1, 5, arr2, 5, arr3);
    printf("%d\n", a);
    return 0;
}