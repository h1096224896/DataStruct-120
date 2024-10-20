#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 链栈的创建
typedef struct LNode {
    int data;  // 数据域
    struct LNode* next;  // 指针域
} LNode;  // 链栈的结点类型定义

typedef struct {
    LNode* top;  // 栈顶指针
} LinkStack;  // 链栈的类型定义

void InitStack(LinkStack* S) {
    S->top = NULL;  // 初始化栈顶指针
}

int StackEmpty(LinkStack S) {
    if (S.top == NULL) {
        return 1;  // 栈空
    }
    else {
        return 0;  // 栈非空
    }
}

int main()
{
    system("pause");
    return 0;
}