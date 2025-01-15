#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100
typedef struct {
    int data[MaxSize];
    int length;
} SqList;


// 利用 2 轮选择排序，找到最大值和次大值
void getMaxAndSecond(SqList* L) {
    for (size_t i = 0; i < 2; i++) {  // 选择排序
        for (size_t j = i + 1; j < L->length; j++) {  // 选择排序
            if (L->data[i] < L->data[j]) {
                int temp = L->data[i];
                L->data[i] = L->data[j];
                L->data[j] = temp;
            }
        }
    }
    printf("%d %d\n", L->data[0], L->data[1]);
}

// 初始化
void InitList(SqList* L) {
    for (int i = 0; i < MaxSize; i++) {
        L->data[i] = 0;
    }
    L->length = 0;
}

// 插入操作
int ListInsert(SqList* L, int pos, int e) {
    for (int i = L->length; i >= pos; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[pos - 1] = e;
    L->length++;
    return 1;
}

// 打印
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}



int main() {
    SqList L;
    InitList(&L);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 3);
    ListInsert(&L, 3, 5);
    ListInsert(&L, 4, 7);
    ListInsert(&L, 5, 9);
    ListInsert(&L, 6, 2);
    ListInsert(&L, 7, 4);
    ListInsert(&L, 8, 6);
    ListInsert(&L, 9, 8);
    ListInsert(&L, 10, 10);
    PrintList(L);
    getMaxAndSecond(&L);
    PrintList(L);
}