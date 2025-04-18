#include <iostream>
using namespace std;

// 1. Tính tổng từ 1 đến n
int sum(int n) {
    if (n == 1) return 1;
    return n + sum(n - 1);
}

// 2. Tính giai thừa
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// 3. Tính số Fibonacci thứ n
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 4. Tính lũy thừa x^n
int power(int x, int n) {
    if (n == 0) return 1;
    return x * power(x, n - 1);
}

// 5. Đếm số chữ số của một số nguyên
int countDigits(int n) {
    if (n < 10) return 1;
    return 1 + countDigits(n / 10);
}

// 6. Tính tổng các chữ số của một số nguyên
int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

// 7. Đảo ngược một số nguyên
int reverseHelper(int n, int rev) {
    if (n == 0) return rev;
    return reverseHelper(n / 10, rev * 10 + n % 10);
}

int reverseNumber(int n) {
    return reverseHelper(n, 0);
}
