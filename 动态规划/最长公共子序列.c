#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int LCSlength(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int* prev = (int*)calloc(len2 + 1, sizeof(int));
    int* curr = (int*)calloc(len2 + 1, sizeof(int));

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1])
                curr[j] = prev[j - 1] + 1;
            else
                curr[j] = prev[j] > curr[j - 1] ? prev[j] : curr[j - 1];
        }
        int* temp = prev;
        prev = curr;
        curr = temp;
    }

    int result = prev[len2];
    free(prev);
    free(curr);
    return result;
}

int main() {
    char str1[1000], str2[1000];
    scanf("%s%s", str1, str2);
    printf("%d\n", LCSlength(str1, str2));
    return 0;
}