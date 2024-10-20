#include <stdio.h>

unsigned long long pow_mod(unsigned long long exp, unsigned long long pow, unsigned long long m) {
    unsigned long long result = 1;
    exp = exp % m;  // m1
    while (pow > 0) {
        if (pow % 2 == 1) {
            result = (result * exp) % m;
        }
        pow = pow / 2;
        exp = (exp * exp) % m;
    }
    return result;
}

int main() {
    unsigned long long exp = 22;
    unsigned long long pow = 45;
    unsigned long long m = 34;
    printf("Result: %llu\n", pow_mod(exp, pow, m));
    return 0;
}