#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    printf("%d\n", Fibonacci(0));
    return 0;
}