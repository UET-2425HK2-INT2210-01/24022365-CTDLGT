#include <iostream>
#include <vector>
using namespace std;

// Hàm đệ quy để sinh dãy nhị phân
void generate(int n, string s = "") {
    if (s.length() == n) {
        cout << s << endl; // In ra khi đủ độ dài
        return;
    }
    generate(n, s + "0"); // Thêm '0'
    generate(n, s + "1"); // Thêm '1'
}

int main() {
    int n;
    cin >> n;
    generate(n);
    return 0;
}
