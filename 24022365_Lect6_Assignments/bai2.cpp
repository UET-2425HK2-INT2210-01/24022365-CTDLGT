#include <iostream>
#include <queue>
using namespace std;

class MinHeap {
private:
    priority_queue<int, vector<int>, greater<int>> heap; 

public:
    // Chèn phần tử vào heap
    void insert(int value) {
        heap.push(value); // Thêm phần tử vào priority_queue
    }

    // Xóa phần tử khỏi heap
    void remove(int value) {
        priority_queue<int, vector<int>, greater<int>> tempHeap; //heap tạm thời
        while (!heap.empty()) {
            if (heap.top() != value) {
                tempHeap.push(heap.top()); // Chỉ giữ lại phần tử khác kp value
            }
            heap.pop(); // Xóa phần tử hiện tại khỏi heap gốc
        }
        heap = tempHeap; // Cập nhật heap
    }

    void printHeap() {
        priority_queue<int, vector<int>, greater<int>> temp = heap; // copy heap hiện tại
        while (!temp.empty()) {
            cout << temp.top() << " "; // In phần tử nhỏ nhất hiện tại
            temp.pop(); // Xóa phần tử vừa in
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap;
    int arr[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int num : arr) heap.insert(num); //build Min-Heap bằng cách thêm từng phần tử
    
    cout << "Heap sau khi tạo: ";
    heap.printHeap(); // In heap ban đầu
    
    // add các giá trị 14, 0, 35 vào Heap
    heap.insert(14);
    heap.insert(0);
    heap.insert(35);
    cout << "Heap sau khi thêm 14, 0, 35: ";
    heap.printHeap(); // In heap sau khi chèn
    
    // Xóa các giá trị 6, 13, 35 khỏi Heap
    heap.remove(6);
    heap.remove(13);
    heap.remove(35);
    cout << "Heap sau khi xóa 6, 13, 35: ";
    heap.printHeap(); // In heap sau khi xóa
    
    return 0;
}
