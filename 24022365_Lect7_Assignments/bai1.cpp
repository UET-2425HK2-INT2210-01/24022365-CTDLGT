#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("numbers.txt"); // Mở file đầu vào
    ofstream fout("numbers.sorted"); // Mở file đầu ra

    vector<double> numbers;
    double x;
    while (fin >> x) { // Đọc từng số thực từ file
        numbers.push_back(x); // Thêm vào vector
    }

    sort(numbers.begin(), numbers.end()); // Sắp xếp tăng dần

    for (double num : numbers) {
        fout << num << " "; // Ghi ra file output, cách nhau bởi khoảng trắng
    }

    fin.close();
    fout.close();
    return 0;
}
