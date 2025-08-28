#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
* 给定程序MODI1.C中函数fun的功能是: 
* 从s所指字符串中，找出与t所指字符串相同的子串的个数作为函数值返回。
* 例如，当s所指字符串中的内容为："abcdabfab"，t所指字符串的 内容为："ab"，则函数返回整数3。
*/
int fun(char* s, char* t) {
    int cnt = 0;  // 计数变量
    while (*s != '\0') {  // 遍历s字符串
        char* ps = s;  // ps指向s的当前字符
        char* pt = t;  // pt指向t的开始字符
        while (*pt != '\0' && *ps == *pt) {  // 只要t的字符没有到达末尾，并且s和t的当前字符相同
            ps++;
            pt++;
        }
        if (*pt == '\0')  // 如果t的指针到达了字符串末尾，说明找到了一个匹配的子串
            cnt++;  // 计数
        s++;  // 移动s指针到下一个字符
    }
    return cnt; 
}

int main() {
    printf("%d\n", fun("abcdabfab", "ab"));
    return 0;
}