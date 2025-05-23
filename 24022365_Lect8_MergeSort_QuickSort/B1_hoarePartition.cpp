#include <iostream>   
#include <vector>     
using namespace std;

int hoarePartition(vector<double>& arr, int low, int high) {
    double pivot = arr[low];  // Chọn phần tử đầu làm pivot
    int i = low - 1;
    int j = high + 1;

    while (true) {
        // Tìm phần tử bên trái lớn hơn hoặc bằng pivot
        do { i++; } while (arr[i] < pivot);
        // Tìm phần tử bên phải nhỏ hơn hoặc bằng pivot
        do { j--; } while (arr[j] > pivot);

        if (i >= j) return j;  // Trả về chỉ số phân hoạch

        swap(arr[i], arr[j]);  // Đổi chỗ hai phần tử
    }
}

void quickSortHoare(vector<double>& arr, int low, int high) {
    if (low < high) {
        int pi = hoarePartition(arr, low, high);  // Lấy chỉ số phân hoạch
        quickSortHoare(arr, low, pi);             // Đệ quy sắp xếp bên trái
        quickSortHoare(arr, pi + 1, high);        // Đệ quy sắp xếp bên phải
    }
}

int main() {
    int n;
    cin >> n;  // Nhập số lượng phần tử

    vector<double> arr(n);  // Khởi tạo vector chứa n phần tử
    for (int i = 0; i < n; i++) cin >> arr[i];  // Nhập các phần tử

    quickSortHoare(arr, 0, n - 1);  // Gọi hàm sắp xếp nhanh

    // In ra mảng đã sắp xếp
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }
    return 0;
}
