#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;  

    vector<int> weight(n);
    vector<int> value(n);

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    // dp[j] là giá trị max với trọng lượng max j
    vector<int> dp(X + 1, 0);

    // Lặp qua từng vật
    for (int i = 0; i < n; i++) {
        // Duyệt ngược từ X về weight[i]
        for (int j = X; j >= weight[i]; j--) {
            // Cập nhật giá trị max
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[X] << endl;

    return 0;
}