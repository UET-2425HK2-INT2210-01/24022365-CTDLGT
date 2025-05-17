#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& arr, int n, int target) {
    //nếu tổng = 0 thì đúng
    if (target == 0) return true;

    // Nếu hết phần tử mà tổng vẫn > 0 thì sai
    if (n == 0) return false;

    // Nếu phần tử cuối lớn hơn tổng thì bỏ
    if (arr[n - 1] > target) {
        return subsetSum(arr, n - 1, target);
    }

    return subsetSum(arr, n - 1, target) ||
           subsetSum(arr, n - 1, target - arr[n - 1]);// chọn ptu cuối hoặc không
}

int main() {
    int n, X;
    cin >> n >> X;              

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];        
    }

    if (subsetSum(arr, n, X)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}