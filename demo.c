#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
请编写函数fun，函数的功能是：判断字符串是否为回文？若是，函数返回1，主函数中输出：YES；否则返回0，主函数中输出NO
回文是指顺读和倒读都一样的字符串。
例如，字符串LEVEL是回文，而字符串123312就不是回文。
*/






// 函数的功能是：判断字符串是否为回文？
int fun(char* str) {
    int i, n = 0, fg = 1;
    char* p = str;
    while (*p) {
        n++;
        p++;
    }
    for (i = 0; i < n / 2; i++) {
        if (*(p - n + i) != *(p - i - 1)) {
            fg = 0;
            break;
        }
    }
    return fg;
}

int main() {
    char s[80];
    // 请输入一个字符串
    gets(s);
    printf("\n");
    puts(s);

    if (fun(s)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}