#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int arr[100];
    int len = 0;
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == -99)
            break;
        arr[len++] = n;
    }
    for (int i = 0; i < len; i++) {
        printf("%-3d", arr[i]);
    }
    printf("\n");
    // 删除重复元素, 选择比较法
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) { // 重复元素
                for (int k = j; k < len - 1; k++) { // 前移
                    arr[k] = arr[k + 1];
                }
                len--;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%-3d", arr[i]);
    }
    printf("\n");
    return 0;
}