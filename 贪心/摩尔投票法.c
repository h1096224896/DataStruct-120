#include <stdio.h>

/*
给定一个大小为n的数组nums，设计一个算法求其中的多数元素。
多数元素是指在数组中出现次数大于[n/2]的元素。
可以假设给定的非空数组中总是存在多数元素。
例如数组为{3,2,3}，结果为3。请写出设计思路。
*/

// 找到数组中的多数元素
int findMajorityElement(int* nums, int len) {
    int candidate = nums[0], count = 1;  // 候选人和票数
    for (int i = 1; i < len; i++) {
        if (nums[i] == candidate)
            count++;
        else
            count--;
        if (count == 0) {
            candidate = nums[i];    // 更新候选人
            count = 1;  // 重置票数
        }
    }
    return candidate;
}

// 主函数测试
int main() {
    int nums[] = { 3, 2, 3,2,2,2,2,2,2 };
    int size = sizeof(nums) / sizeof(nums[0]);

    int majority = findMajorityElement(nums, size);
    if (majority != -1) {
        printf("多数元素是: %d\n", majority);
    }
    else {
        printf("未找到多数元素\n");
    }

    return 0;
}