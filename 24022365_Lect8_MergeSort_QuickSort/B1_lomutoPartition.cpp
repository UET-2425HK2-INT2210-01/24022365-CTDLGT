#include <iostream>   
#include <vector>    
using namespace std;

int lomutoPartition(vector<double>& arr, int low, int high) {
    double pivot = arr[high];  // Chọn phần tử cuối cùng làm pivot
    int i = low - 1;           // Khởi tạo chỉ số i trước vùng phân tách

    // Duyệt qua các phần tử từ low đến high - 1
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {     
            i++;                   
            swap(arr[i], arr[j]);  
        }
    }
    // Đặt pivot vào đúng vị trí (giữa 2 vùng lớn hơn và nhỏ hơn)
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Trả về chỉ số pivot sau khi phân hoạch
}

void quickSortLomuto(vector<double>& arr, int low, int high) {
    if (low < high) {
        int pi = lomutoPartition(arr, low, high);   // Tìm chỉ số phân hoạch
        quickSortLomuto(arr, low, pi - 1);          // Đệ quy cho nửa bên trái
        quickSortLomuto(arr, pi + 1, high);         // Đệ quy cho nửa bên phải
    }
}

int main() {
    int n;
    cin >> n; 

    vector<double> arr(n);  
    for (int i = 0; i < n; i++) cin >> arr[i];  

    quickSortLomuto(arr, 0, n - 1); 

    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }
    return 0;
}

