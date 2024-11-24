#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 // 栈的最大容量

// 定义栈结构
typedef struct {
    char data[MAX_SIZE];
    int top; // 栈顶指针
} Stack;

// 初始化栈
void initStack(Stack* stack) {
    stack->top = -1; // 栈顶指针初始化为-1，表示空栈
}

// 检查栈是否为空
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 检查栈是否已满
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// 入栈操作
int push(Stack* stack, char item) {
    if (isFull(stack))
        return 0; // 入栈失败，栈已满
    stack->data[++stack->top] = item;
    return 1; // 入栈成功
}

// 出栈操作
int pop(Stack* stack) {
    if (isEmpty(stack))
        return 0; // 出栈失败，栈为空
    stack->top--;
    return 1; // 出栈成功
}

// 括号匹配检查函数
int checkParentheses(char* expression) {
    Stack stack;
    initStack(&stack);
    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];  // 逐个读取表达式中的字符
        if (ch == '(') {
            // 左括号入栈
            if (!push(&stack, ch))
                return 0; // 栈溢出
        }
        else if (ch == ')') {
            // 右括号需要匹配栈顶的左括号
            if (!pop(&stack))
                return 0; // 匹配失败
        }
    }
    // 栈为空表示匹配成功，否则匹配失败
    return isEmpty(&stack);
}

// 主函数
int main() {
    char expression[MAX_SIZE];
    printf("请输入一串括号：");
    scanf("%s", expression);

    if (checkParentheses(expression)) {
        printf("括号匹配\n");
    }
    else {
        printf("括号不匹配\n");
    }
    return 0;
}