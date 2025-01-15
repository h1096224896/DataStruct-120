#include <stdio.h>
#include <stdlib.h>

// 合并函数，计算逆序对，并将数组归并
int mergeAndCount(int* arr, int* temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int invCount = 0;

    // 归并排序的合并过程
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);  // 计算逆序对的个数
        }
    }

    // 复制剩余的元素
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // 将排序结果拷贝回原数组
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

// 递归函数，通过归并排序计算逆序对
int mergeSortAndCount(int* arr, int* temp, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 递归左边
        invCount += mergeSortAndCount(arr, temp, left, mid);

        // 递归右边
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);

        // 合并两部分，并计算逆序对
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}

// 获取逆序对总数的接口函数
int countInversePairs(int* nums, int numsSize) {
    int* temp = (int*)malloc(numsSize * sizeof(int));  // 临时数组
    int result = mergeSortAndCount(nums, temp, 0, numsSize - 1);
    free(temp);
    return result;
}

int main() {
    int nums[] = { 7, 5, 6, 4 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = countInversePairs(nums, numsSize);
    printf("逆序对的数量: %d\n", result);  // 输出结果应为 5

    return 0;
}