#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 100
typedef struct {
    int data[MaxSize];
    int length;
} SqList;


// 从第i个位置开始删除k个元素
void delete(SqList* L, int i, int k) {
    if (L == NULL) return;  // 顺序表为空
    for (int count = 0; count < k; count++) {  // 外层循环控制删除个数.
        for (int j = i - 1; j < L->length; j++) {  // 数组下标从0开始,i-1
            L->data[j] = L->data[j + 1];  // 内层循环从开始删除位置每删除一个元素,后续元素都要向前移动
        }
        L->length--;  // 删除元素后,数组长度对应减1
    }
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
    // your code here~
    delete(&L, 3, 3);
    PrintList(L);
}