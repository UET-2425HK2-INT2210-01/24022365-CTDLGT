#include <iostream>
#include <vector>
using namespace std;

void merge(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<double> L(n1), R(n2);

    // Sao chép dữ liệu vào mảng trái L và mảng phải R
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    // So sánh và trộn hai mảng con lại theo thứ tự tăng dần
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    // Nếu mảng L còn phần tử chưa xét thì chép vào arr
    while (i < n1) arr[k++] = L[i++];
    // Nếu mảng R còn phần tử chưa xét thì chép vào arr
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<double> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }
    return 0;
}
