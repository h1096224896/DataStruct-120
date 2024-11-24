#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 栈的创建
#define MAXSIZE 100
typedef struct {
    char data[MAXSIZE];  // 用来存放栈中元素
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
int Push(SqStack* S, char x) {
    if (S->top == MAXSIZE - 1)
        return 0;  // 栈满
    S->data[++S->top] = x;  // 将新插入元素放入栈顶
    return 1;
}

// 出栈
int Pop(SqStack* S, char* x) {
    if (S->top == -1)
        return 0;  // 栈空
    *x = S->data[S->top--];  // 将栈顶元素用x返回，栈顶指针减1
    return 1;
}

// 读栈顶元素
int GetTop(SqStack S, char* x) {
    if (S.top == -1)
        return 0;  // 栈空
    *x = S.data[S.top];  // 返回栈顶元素
    return 1;
}

// 销毁栈
void DestroyStack(SqStack* S) {
    S->top = -1;  // 栈顶指针置为-1
}

// 检查表达式中的括号是否匹配
int checkParentheses(char* expression) {
    SqStack S;
    InitStack(&S);
    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];  // 逐个读取表达式中的字符
        if (ch == '(') {
            // 左括号入栈
            if (!Push(&S, ch))
                return 0; // 栈溢出
        }
        else if (ch == ')') {
            // 右括号需要匹配栈顶的左括号
            char top;
            if (!Pop(&S, &top))
                return 0; // 匹配失败
        }
    }
    return StackEmpty(S); // 栈为空表示匹配成功，否则匹配失败
}

int main() {
    char expression[100];
    printf("请输入表达式：");
    scanf("%s", expression);
    if (checkParentheses(expression)) {
        printf("括号匹配成功\n");
    }
    else {
        printf("括号匹配失败\n");
    }
    return 0;
}