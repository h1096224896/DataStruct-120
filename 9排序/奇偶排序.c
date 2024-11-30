#include <stdio.h>


// 函数定义: 调整数组，使左边是奇数，右边是偶数
void rearrangeArray(int AInl[], int n) {
    int left = 0;         // 左指针
    int right = n - 1;    // 右指针
    while (left < right) {
        // 左指针移动，直到找到一个偶数
        while (left < right && AInl[left] % 2 != 0) {
            left++;
        }
        // 右指针移动，直到找到一个奇数
        while (left < right && AInl[right] % 2 == 0) {
            right--;
        }
        // 如果左指针小于右指针，交换两个元素
        if (left < right) {
            int temp = AInl[left];
            AInl[left] = AInl[right];
            AInl[right] = temp;
        }
    }
}

// 主函数示例
int main() {
    int AInl[] = { 12, 17, 19, 8, 7, 4, 6, 21 };
    int n = sizeof(AInl) / sizeof(AInl[0]);

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
