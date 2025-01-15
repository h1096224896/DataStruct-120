#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 摩尔投票法求多数元素
int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];  // 候选人
    int count = 1;  // 计数器
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == candidate) {
            count++;
        }
        else {
            count--;
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }
    return candidate;
}

int main() {
    int arr[] = { 2, 2, 1, 1, 1, 2, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", majorityElement(arr, n));
    return 0;
}