#include <iostream>
#include <vector>
using namespace std;

bool found = false;

void backscat(const vector<int>& arr, int index, int currentSum, int target) {
    if (currentSum == target) {
        found = true;  
        return;
    }

    // Nếu đã xét hết mảng hoặc tổng hiện tại vượt quá target => dừng
    if (index >= arr.size() || currentSum > target) return;

    // Gọi đệ quy với việc chọn phần tử hiện tại
    backscat(arr, index + 1, currentSum + arr[index], target);

    // Gọi đệ quy với việc không chọn phần tử hiện tại
    backscat(arr, index + 1, currentSum, target);
}

int main() {
    int n, X;
    cin >> n >> X;  

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];  

    // Gọi hàm quay lui bắt đầu từ chỉ số 0 và tổng hiện tại là 0
    backscat(arr, 0, 0, X);

    if (found)
        cout << "YES";  
    else
        cout << "NO";  

    return 0;
}
