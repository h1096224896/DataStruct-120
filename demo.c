#include <stdio.h>
#include <ctype.h>
void  fun(char* p) {
    int  i = 0;
    while (p[i]) {
        if (p[i] == ' ' && islower(p[i - 1]))
            p[i - 1] = p[i - 1] - 'a' + 'A';
        i++;
    }
}

int main() {
    char s1[100] = "ab cd EFG！";
    fun(s1);
    printf("%s\n", s1);
}