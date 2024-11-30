#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 设计一个函数，求用邻接矩阵表示的有向图中序号为 num 的顶点的度（入度和出度之和），其中邻接矩阵、有向图的顶点数、num 的值作为参数传入。
// 抽象为求一个二维数组的第 num 行和第 num 列的和
int degree(int arr[][5], int n, int num) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[num][i];
    }
    for (int i = 0; i < n; i++) {
        sum += arr[i][num];
    }
    return sum;
}


int main() {
    int arr[5][5] = {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    int n = 5;
    int num = 2;
    printf("顶点 %d 的度为: %d\n", num, degree(arr, n, num));
    return 0;
}