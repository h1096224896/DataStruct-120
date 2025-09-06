#include <stdio.h>
#include <stdlib.h>




// =============== 1. 指针函数（返回指针的函数） ===============

// 指针函数：返回一个指向 int 的指针
// 这里使用 static 避免返回局部变量地址（否则会出错）
int* create_array() {
    static int arr[5] = { 10, 20, 30, 40, 50 };
    printf("指针函数：create_array 返回数组首地址\n");
    return arr;  // 返回指向 int 的指针
}

// 指针函数：返回字符串（字符指针）
char* get_greeting() {
    return "Hello from pointer function!";
}

// =============== 2. 函数指针（指向函数的指针） ===============

// 定义几个简单的函数，用于函数指针调用
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

// 函数指针作为参数（回调函数）
void compute(int x, int y, int (*operation)(int, int)) {
    int result = operation(x, y);
    printf("函数指针调用结果: %d\n", result);
}

int main() {
    printf("=== 指针函数和函数指针 示例 ===\n\n");

    // ---------- 指针函数使用 ----------
    printf("【指针函数示例】\n");

    // 调用返回 int* 的函数
    int* ptr_arr = create_array();
    printf("通过指针访问数组元素: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr_arr[i]);
    }
    printf("\n\n");

    // 调用返回 char* 的函数
    char* greeting = get_greeting();
    printf("字符串指针函数返回: %s\n\n", greeting);

    // ---------- 函数指针使用 ----------
    printf("【函数指针示例】\n");

    // 声明函数指针，指向返回 int、接受两个 int 参数的函数
    int (*func_ptr)(int, int);

    // 指向 add 函数
    func_ptr = add;
    printf("func_ptr 指向 add: %d\n", func_ptr(5, 3));  // 输出 8

    // 指向 multiply 函数
    func_ptr = multiply;
    printf("func_ptr 指向 multiply: %d\n", func_ptr(5, 3));  // 输出 15

    // 使用函数指针作为回调
    printf("\n使用函数指针作为回调:\n");
    compute(10, 4, add);        // 输出 14
    compute(10, 4, multiply);   // 输出 40

    // ---------- 函数指针数组（进阶）----------
    printf("\n【函数指针数组示例】\n");
    int (*operations[2])(int, int) = { add, multiply };

    printf("operations[0](6, 7) = %d\n", operations[0](6, 7));  // add: 13
    printf("operations[1](6, 7) = %d\n", operations[1](6, 7));  // multiply: 42
    printf("%d\n", );
    
    return 0;
}