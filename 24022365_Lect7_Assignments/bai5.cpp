#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = i + 1; // Khởi tạo 1..n

    do {
        for (int x : a)
            cout << x;
        cout << endl;
    } while (next_permutation(a.begin(), a.end())); // Sinh hoán vị kế tiếp

    return 0;
}
