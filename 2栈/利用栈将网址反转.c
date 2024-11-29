#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 栈的定义
#define MAX_SIZE 100

typedef struct {
    char* data[MAX_SIZE]; // 存储字符串指针的栈
    int top;              // 栈顶指针
} Stack;

// 栈的初始化
void initStack(Stack* s) {
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 判断栈是否满
int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

// 入栈操作
void push(Stack* s, char* str) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++(s->top)] = str;
}

// 出栈操作
char* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return NULL;
    }
    return s->data[(s->top)--];
}

// 栈顶操作
char* top(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return NULL;
    }
    return s->data[s->top];
}

// 分割字符串并反转
void reverseDomain(char* domain) {
    Stack s;
    initStack(&s);

    char* token = strtok(domain, "."); // 按照"."分割
    while (token != NULL) {         // 分割结束条件
        push(&s, token); // 分割出的每段入栈
        token = strtok(NULL, ".");  // 继续分割
    }

    // 拼接反转后的域名
    while (!isEmpty(&s)) {
        printf("%s", pop(&s)); // 出栈打印每段
        if (!isEmpty(&s)) {
            printf(".");
        }
    }
    printf("\n");
}

int main() {
    char domain1[] = "www.sut.edu.cn";
    char domain2[] = "www.baidu.com";

    printf("Original: %s\nReversed: ", domain1);
    reverseDomain(domain1);

    printf("Original: %s\nReversed: ", domain2);
    reverseDomain(domain2);

    return 0;
}