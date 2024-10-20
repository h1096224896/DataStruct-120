#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define InitSize 10
typedef struct {
    int* data;
    int MaxSize;
    int length;
} SeqList;

void InitList(SeqList* L) {
    L->data = (int*)malloc(InitSize * sizeof(int));
    L->length = 0;
    L->MaxSize = InitSize;
}


// 按值查找,返回其位序
int LocateElem(SeqList L, int e) {
    for (size_t i = 0; i < L.length; i++) {
        if (e == L.data[i])
            return i + 1;
    }
    return -1;
}

// 逆序
void reverseList(SeqList* L) {
    int temp;
    for (size_t i = 0; i < L->length / 2; i++) {
        temp = L->data[i];
        L->data[i] = L->data[L->length - i - 1];
        L->data[L->length - i - 1] = temp;
    }
}

// 删除最小元素,并将最小元素返回
void deleteMinValue(SeqList* L, int* e) {
    int min = L->data[0];
    if (L->length == 0)
        return;
    int pos = 0;
    for (size_t i = 1; i < L->length; i++) {
        if (L->data[i] < min) {
            min = L->data[i];
            pos = i;
        }
    }
    *e = min;
    L->data[pos] = L->data[L->length - 1];
    L->length--;
}
void showList(SeqList L) {
    for (size_t i = 0; i < L.length; i++) {
        printf("%-3d", L.data[i]);
    }
    printf("\n");
}

int main(int argc, char const* argv[]) {
    SeqList L;
    InitList(&L);
    int value;
    for (size_t i = 0; i < 10; i++) {
        L.data[i] = i * i;
        L.length++;
    }
    showList(L);
    reverseList(&L);
    showList(L);
    deleteMinValue(&L, &value);
    printf("%d", value);
    return 0;
}
