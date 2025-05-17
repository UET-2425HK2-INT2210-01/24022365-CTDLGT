#include <iostream>      
#include <vector>        
using namespace std;

// hoán đổi hai giá trị 
void swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

int partition(vector<double> &arr, int low, int high) {
    double pivot = arr[high];     // Chọn phần tử cuối làm pivot
    int i = low - 1;              // Vị trí của ptu nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {    
            i++;                 
            swap(arr[i], arr[j]); // Đưa phần tử nhỏ hơn về đầu
        }
    }

    // Đặt pivot vào đúng vị trí giữa hai phần
    swap(arr[i + 1], arr[high]);
    return i + 1;  
}

void quickSort(vector<double> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Tìm chỉ số pivot

        //sắp xếp hai phần
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }
}

int main() {
    int n;
    cin >> n;   

    vector<double> arr(n); 

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }

    return 0; 
}