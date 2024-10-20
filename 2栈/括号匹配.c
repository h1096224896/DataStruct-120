#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 假设一个算术表达式中包含圆括号、方括号和花括号3种类型的括号，编写一个算法来判别表达式中的括号是否配对，以字符“\0”作为算术表达式的结束符。
int bracketMatch(char* str) {
    char stack[100];
    int top = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stack[++top] = str[i];
        }
        else if (str[i] == ')') { 
            if (top == -1 || stack[top] != '(') {
                return 0;
            }
            top--;
        }
        else if (str[i] == ']') {
            if (top == -1 || stack[top] != '[') {
                return 0;
            }
            top--;
        }
        else if (str[i] == '}') {
            if (top == -1 || stack[top] != '{') {
                return 0;
            }
            top--;
        }
    }
    if (top == -1) {
        return 1;
    }
    return 0;
}

int main() {
    char str[100];
    printf("Please input a string: ");
    scanf("%s", str);
    if (bracketMatch(str)) {
        printf("The brackets are matched.\n");
    }
    else {
        printf("The brackets are not matched.\n");
    }
    return 0;
}