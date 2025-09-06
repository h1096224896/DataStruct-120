#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 归并法求逆序对
int merge(int* nums, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    int count = merge(nums, left, mid) + merge(nums, mid + 1, right);
    int* temp = (int*)malloc((right - left + 1) * sizeof(int));
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        }
        else {
            temp[k++] = nums[j++];
            count += mid - i + 1;
        }
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];
    memcpy(nums + left, temp, (right - left + 1) * sizeof(int));
    free(temp);
    return count;
}

int main()
{
    int arr[] = { 7, 5, 6, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", merge(arr, 0, n - 1));
    return 0;
}