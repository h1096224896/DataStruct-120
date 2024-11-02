#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cmpCountSort(int a[], int b[], int n) {
    int i, j, * count;
    count = (int*)malloc(sizeof(int) * n);
    for (i = 0;i < n;i++)
        count[i] = 0;
    for (i = 0;i < n - 1;i++)
        for (j = i + 1;j < n;j++)
            if (a[i] < a[j]) count[j]++;
            else count[i]++;
    for (i = 0;i < n;i++) b[count[i]] = a[i];
    free(count);
}
int main() {
    int a[] = { 25,-10,25,10,11,19 };
    int b[6];
    cmpCountSort(a, b, 6);
    for (size_t i = 0; i < 6; i++) {
        printf("%-3d", b[i]);
    }
    return 0;
}