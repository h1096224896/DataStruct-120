#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 栈的创建
#define MAXSIZE 100
typedef struct {
    int data[MAXSIZE];  // 用来存放栈中元素
    int top;        // 用来指示栈顶元素在数组中的位置,数组下标从0开始
} SqStack;  // 顺序栈的类型定义

void InitStack(SqStack* S) {
    S->top = -1;  // 初始化栈顶指针
}

int StackEmpty(SqStack S) {
    if (S.top == -1) {
        return 1;  // 栈空
    }
    else {
        return 0;  // 栈非空
    }
}

int Stackfull(SqStack S) {
    if (S.top == MAXSIZE - 1) {
        return 1;  // 栈满
    }
    else {
        return 0;  // 栈非满
    }
}

// 进栈
int Push(SqStack* S, int x) {
    if (S->top == MAXSIZE - 1) {
        return 0;  // 栈满
    }
    S->top++;  // 栈顶指针加1
    S->data[S->top] = x;  // 将新插入元素放入栈顶
    return 1;
}

// 出栈
int Pop(SqStack* S, int* x) {
    if (S->top == -1) {
        return 0;  // 栈空
    }
    *x = S->data[S->top];  // 将栈顶元素出栈
    S->top--;  // 栈顶指针减1
    return 1;
}

// 读栈顶元素
int GetTop(SqStack S, int* x) {
    if (S.top == -1) {
        return 0;  // 栈空
    }
    *x = S.data[S.top];  // 返回栈顶元素
    return 1;
}

// 销毁栈
void DestroyStack(SqStack* S) {
    S->top = -1;  // 栈顶指针置为-1
}



int main() {
    SqStack S;
    InitStack(&S);
    int x;
    for (size_t i = 0; i < 10; i++) {
        Push(&S, i);
    }
    for (size_t i = 0; i < 10; i++) {
        Pop(&S, &x);
        printf("%d ", x);
    }
    printf("\n");
    StackEmpty(S);
    return 0;
}