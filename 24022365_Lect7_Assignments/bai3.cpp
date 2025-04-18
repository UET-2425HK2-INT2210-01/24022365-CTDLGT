#include <iostream>
using namespace std;

// Hàm GCD đệ quy
int gcd(int a, int b) {
    if (b == 0) return a; // Điều kiện dừng
    return gcd(b, a % b); // Gọi đệ quy
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;
    return 0;
}
