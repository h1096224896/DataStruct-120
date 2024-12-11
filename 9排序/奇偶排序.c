#include <stdio.h>
#include <stdlib.h>

// 函数定义: 调整数组，使左边是奇数，右边是偶数
void rearrangeArray(int arr[], int n) {
    int left = 0;         // 左指针
    int right = n - 1;    // 右指针
    while (left < right) {
        // 左指针移动，直到找到一个偶数
        while (left < right && arr[left] % 2 == 1)  // 奇数
            left++;
        // 右指针移动，直到找到一个奇数
        while (left < right && arr[right] % 2 == 0)  // 偶数
            right--;
        // 如果左指针小于右指针，交换两个元素
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

// 主函数示例
int main() {
    #define n 10
    int AInl[n];
    for (int i = 0; i < n; i++) {
        AInl[i] = arc4random() % 100;
    }
    printf("原数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", AInl[i]);
    }
    rearrangeArray(AInl, n);
    printf("\n调整后数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", AInl[i]);
    }

    return 0;
}
