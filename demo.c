#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// 编程帮我验证,n+1的对数向上取整和先向下取整再加1是否相等
int main() {
    for (size_t i = 1; i < 100; i++) {
        int n = i;
        int layer1, layer2;
        layer1 = log(n) / log(2) + 1;
        // layer2 = log(n + 1) / log(2); 向上取整
        layer2 = log(n + 1) / log(2) + 1; // 向下取整再加1
        if (layer1 != layer2) {
            printf("n=%d, layer1=%d, layer2=%d\n", n, layer1, layer2);
        }
    }

    return 0;
}