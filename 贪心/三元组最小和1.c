#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


// 1.	三指针法：对于每个集合  S_1, S_2, S_3 ，分别维护一个指针  i, j, k ，初始时均指向集合的起始位置。
// 2.	计算当前距离：对于当前三元组(x, y, z) = (S_1[i], S_2[j], S_3[k]) ，计算其距离  D = | x - y | +| y - z | +| z - x | 。
// 3.	更新指针：选择当前最小值的集合指针向前移动，因为增加较小值有可能减少总距离  D 。
// 4.	终止条件：当任一指针到达其对应数组的末尾时，停止循环，因为无法再形成新的三元组。
// 5.	优化目标：在每一步更新最小距离  D_{ \text{min} }  及其对应的三元组。

// 计算距离函数
int calculateDistance(int x, int y, int z) {
    return abs(x - y) + abs(y - z) + abs(z - x);
}

// 主算法
void findMinDistance(int* S1, int len1, int* S2, int len2, int* S3, int len3) {
    int resultX = 0, resultY = 0, resultZ = 0; // 最优三元组的下标
    int minDistance = calculateDistance(S1[0], S2[0], S3[0]);  // 先默认第一个三元组为最小距禋
    int i = 1, j = 1, k = 1;
    while (i < len1 && j < len2 && k < len3) {
        int x = S1[i], y = S2[j], z = S3[k];
        int currentDistance = calculateDistance(x, y, z);  // 计算当前距离
        // 更新最小距离和结果
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            resultX = x;
            resultY = y;
            resultZ = z;
        }
        // 移动指针：最小值的指针向前
        if (x <= y && x <= z)
            i++;
        else if (y <= x && y <= z)
            j++;
        else
            k++;
    }

    // 输出结果
    printf("最小距离为: %d\n", minDistance);
    printf("相应的三元组为: (%d, %d, %d)\n", resultX, resultY, resultZ);
}

// 测试主函数
int main() {
    int S1[] = { -1, 0, 9 };
    int S2[] = { -25, -10, 10, 11 };
    int S3[] = { 2, 9, 17, 30, 41 };
    int n1 = sizeof(S1) / sizeof(S1[0]);
    int n2 = sizeof(S2) / sizeof(S2[0]);
    int n3 = sizeof(S3) / sizeof(S3[0]);

    findMinDistance(S1, n1, S2, n2, S3, n3);

    return 0;
}