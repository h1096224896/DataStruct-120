#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
    已知一棵二叉树按顺序存储结构进行存储，设计一个算法，
    求编号分别为i和j的两个结点的最近的公共祖
*/
// 公共祖先
int getLCA(int arr[], int i, int j) {
    int layer1, layer2;
    layer1 = log(i) / log(2) + 1;  // 层数
    layer2 = log(j) / log(2) + 1;
    if (i <= 0 || j <= 0) {
        return -1; // Invalid indices
    }
    while (layer1 < layer2) {
        j = j / 2;
        layer2 = log(j) / log(2) + 1;  // 求所在层数
    }
    while (layer1 > layer2) {
        i = i / 2;
        layer1 = log(i) / log(2) + 1;
    }
    while (i != j) {
        i /= 2;
        j /= 2;
    }
    return arr[i - 1];
}

int main() {
    int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    printf("%d\n", getLCA(arr, 10, 12));
    return 0;
}