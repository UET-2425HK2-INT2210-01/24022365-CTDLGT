#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ifstream fin("matrix.txt");
    ofstream fout("matrix.out");

    int m, n;
    fin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));

    // Đọc ma trận từ file
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            fin >> a[i][j];

    int maxSum = INT_MIN;
    int r1, c1, r2, c2;

    // Duyệt tất cả các cặp dòng bắt đầu và kết thúc
    for (int top = 0; top < m; ++top) {
        vector<int> temp(n, 0); // Mảng cộng dồn cột
        for (int bottom = top; bottom < m; ++bottom) {
            for (int k = 0; k < n; ++k)
                temp[k] += a[bottom][k]; // Cộng dồn từ dòng top đến bottom

            // Tìm đoạn con có tổng lớn nhất trên mảng 1 chiều
            int sum = 0, start = 0;
            for (int i = 0; i < n; ++i) {
                if (sum <= 0) {
                    sum = temp[i];
                    start = i;
                } else {
                    sum += temp[i];
                }
                if (sum > maxSum) {
                    maxSum = sum;
                    r1 = top + 1; c1 = start + 1;
                    r2 = bottom + 1; c2 = i + 1;
                }
            }
        }
    }

    fout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum << endl;

    return 0;
}
