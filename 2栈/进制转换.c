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
    // 将栈中所有元素置为空
    for (int i = 0; i < MAXSIZE; i++) {
        S->data[i] = 0;
    }
}

int StackEmpty(SqStack S) {
    if (S.top == -1)
        return 1;  // 栈空
    else
        return 0;  // 栈非空
}

int Stackfull(SqStack S) {
    if (S.top == MAXSIZE - 1)
        return 1;  // 栈满
    else
        return 0;  // 栈非满
}

// 进栈
int Push(SqStack* S, int x) {
    if (S->top == MAXSIZE - 1)
        return 0;  // 栈满
    S->data[++S->top] = x;  // 将新插入元素放入栈顶
    return 1;
}

// 出栈
int Pop(SqStack* S, int* x) {
    if (S->top == -1)
        return 0;  // 栈空
    *x = S->data[S->top--];  // 将栈顶元素用x返回，栈顶指针减1
    return 1;
}

// 读栈顶元素
int GetTop(SqStack S, int* x) {
    if (S.top == -1)
        return 0;  // 栈空
    *x = S.data[S.top];  // 返回栈顶元素
    return 1;
}

// 销毁栈
void DestroyStack(SqStack* S) {
    S->top = -1;  // 栈顶指针置为-1
}


// 十进制转换为二进制
// 基本思路: 除2取余，逆序输出
void DecToBin(int n) {
    SqStack S;
    InitStack(&S);
    while (n) {
        Push(&S, n % 2);
        n /= 2;
    }
    while (!StackEmpty(S)) {
        int ch;
        Pop(&S, &ch);
        printf("%d", ch);
    }
    printf("\n");
}

// 递归
void DecToBin2(int n) {
    if (n) {
        DecToBin2(n / 2);
        printf("%d", n % 2);
    }
}

int main() {
    int n;
    printf("请输入一个十进制数：");
    scanf("%d", &n);
    DecToBin(n);
    // DecToBin2(n);
    return 0;
}