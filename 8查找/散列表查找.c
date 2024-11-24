#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int hash[13] = { 0 };
    for (int i = 0; i < 10; i++) {
        int num;
        scanf("%d", &num);
        int pos = num;
        while (hash[pos % 13] != 0) { // 有数
            pos++;
        }
        hash[pos % 13] = num;
    }
    for (size_t i = 0; i < 13; i++) {
        printf("%-3d", hash[i]);
    }
    printf("\n");

    printf("请输入要查找的元素:");
    int x;
    scanf("%d", &x);
    int isfind = 0;
    int i;
    for (i = x % 13; i < 13; i++) {
        if (hash[i] == x) {
            isfind = 1;
            break;
        }
    }
    if (isfind) {
        printf("在第%d个位置找到元素%d", i, x);
    }
    else
        printf("查找失败\n");
    return 0;
}