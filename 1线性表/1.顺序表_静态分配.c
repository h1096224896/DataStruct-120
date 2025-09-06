#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100
typedef struct {
    int data[MaxSize];
    int length;
} SqList;


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

// 删除操作(用e返回)
int ListDelete(SqList* L, int pos, int* e) {
    if (pos < 1 || pos > L->length)
        return 0;
    *e = L->data[pos - 1]; // 讲被删除的元素赋值给e
    for (int j = pos; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return 1;
}

// 按位查找
int GetElem(SqList L, int pos) {
    return L.data[pos - 1];
}

// 打印
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}


int del_min(SqList* L, int* value) {
    if (L->length == 0) return 0;
    *value = L->data[0];
    int pos = 0;
    for (int i = 1; i < L->length; i++) {
        if (L->data[i] < *value) {
            *value = L->data[i];
            pos = i;
        }
    }
    L->data[pos] = L->data[L->length - 1];
    L->length--;
    return 1;
}

bool reverseSqList(SqList* L, int start, int end) {
    int temp;
    while (start < end) {
        temp = L->data[start];
        L->data[start] = L->data[end];
        L->data[end] = temp;
        start++;
        end--;
    }
    return true;
}


// 编写一个时间复杂度为O(n),空间复杂度为O(1),删除顺序表中所有元素为x的元素
bool delete_x(SqList* L, int x) {
    int k = 0;  // 记录不等于x的元素个数
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] != x) {  // 如果不等于x,则将其赋值给L->data[k]
            L->data[k] = L->data[i];  // 保留
            k++;  // 
        }
    }
    L->length = k;
    return true;
}

// 从有序顺序表中删除其值在给定s和t之间的所有元素
bool deleteFromSToT(SqList* L, int s, int t) {
    if (s >= t || L->length == 0) return false; // 
    int i = 0, j = 0;
    // 找到第一个大于等于 s 的元素位置
    for (i = 0; i < L->length; i++) {
        if (L->data[i] >= s)
            break;
    }
    if (i >= L->length) return false; // 所有的数都比 s 小
    // 找到第一个大于 t 的元素位置
    for (j = i; j < L->length; j++) {
        if (L->data[j] > t)
            break;
    }
    // 将后续元素前移
    for (; j < L->length; i++, j++) {
        L->data[i] = L->data[j];
    }
    L->length = i; // 更新顺序表的长度
    return true;
}

// 删除所有重复的元素,使得每个元素只出现一次
bool deleteSame(SqList* L) {
    if (L->length == 0) return false;  // 空表
    int i, j;
    for (i = 0, j = 1; j < L->length; j++) {  // 从第二个元素开始遍历
        if (L->data[i] != L->data[j]) {  // 如果不相等,则将其赋值给L->data[++i]
            L->data[++i] = L->data[j];
        }
    }
    L->length = i + 1;  // 更新顺序表的长度
    return true;
}

// 将两个有序顺序表合并成一个有序顺序表(归并排序)
bool merge(SqList A, SqList B, SqList* C) {
    if (A.length + B.length > MaxSize) return false;  // 合并后的长度大于MaxSize
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {  // 两个顺序表都未遍历完
        if (A.data[i] < B.data[j]) {
            C->data[k++] = A.data[i++];
        }
        else {
            C->data[k++] = B.data[j++];
        }
    }
    while (i < A.length) {  // A未遍历完
        C->data[k++] = A.data[i++];
    }
    while (j < B.length) {  // B未遍历完
        C->data[k++] = B.data[j++];
    }
    C->length = k;  // 更新顺序表的长度
    return true;
}

// 顺序表数组中存放着两个有顺序表(a1,a2,a3,...,am)和(b1,b2,b3,...,bn),要求将第二个顺序表放到第一个顺序表的前面,第一个顺序表放到第二个顺序表的后面,两个顺序表的元素顺序不变
bool reverse(SqList* L, int m, int n) {  // 将顺序表L中的前m个元素和后n个元素逆置
    if (m + n > MaxSize) return false;  // 两个顺序表的长度之和大于MaxSize
    reverseSqList(L, 0, L->length - 1);  // 将整个顺序表逆置
    reverseSqList(L, 0, m - 1);  // 将前m个元素逆置
    reverseSqList(L, m, m + n - 1);  // 将后n个元素逆置
    return true;
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
    PrintList(L);
}