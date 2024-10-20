#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_next(char* str, int* next) {
    int i = 0, j = -1;
    next[0] = -1;
    while (str[i] != '\0') {
        if (j == -1 || str[i] == str[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

int Index_KMP(char* s, char* t, int next[]) {
    int i = 0, j = 0;
    while (s[i] != '\0' && t[j] != '\0') {
        if (j == -1 || s[i] == t[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    if (t[j] == '\0') {
        return i - j;
    }
    return -1;
}

// BF暴力匹配


int main() {
    char s[] = "abaabaabca";
    char t[] = "abaabc";
    int next[7];
    get_next(t, next);
    printf("%d\n", Index_KMP(s, t, next));
    return 0;
}