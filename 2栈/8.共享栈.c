#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 共享栈的创建
#define MAXSIZE 100
typedef struct {
    int data[MAXSIZE];  // 用来存放栈中元素
    int top1;        // 用来指示栈1的栈顶元素在数组中的位置,数组下标从0开始
    int top2;        // 用来指示栈2的栈顶元素在数组中的位置,数组下标从MAXSIZE-1开始
} ShStack;  // 共享栈的类型定义

void InitStack(ShStack *S) {
    S->top1 = -1;  // 初始化栈1的栈顶指针
    S->top2 = MAXSIZE;  // 初始化栈2的栈顶指针
}

int StackEmpty(ShStack S, int i) {  // i=1表示栈1，i=2表示栈2
    if (i == 1) {
        if (S.top1 == -1) {
            return 1;  // 栈1空
        } else {
            return 0;  // 栈1非空
        }
    } else {
        if (S.top2 == MAXSIZE) {
            return 1;  // 栈2空
        } else {
            return 0;  // 栈2非空
        }
    }
}

int main()
{
    
    return 0;
}