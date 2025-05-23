#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPath(vector<vector<int>>& adj, int n, int X, int Y) {
    vector<int> distance(n + 1, -1); // Lưu khoảng cách từ X đến các nút
    queue<int> q;
    
    distance[X] = 0; // Khoảng cách từ X đến chính nó là 0
    q.push(X);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // Duyệt qua tất cả các nút kề
        for (int neighbor : adj[current]) {
            if (distance[neighbor] == -1) { // Nếu chưa được thăm
                distance[neighbor] = distance[current] + 1;
                
                // Nếu tìm thấy Y thì trả về kết quả ngay
                if (neighbor == Y) {
                    return distance[neighbor];
                }
                
                q.push(neighbor);
            }
        }
    }
    
    return -1; // Không có đường đi từ X đến Y
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    
    // Tạo danh sách kề cho đồ thị có hướng
    vector<vector<int>> adj(n + 1); // Sử dụng index từ 1 đến n
    
    // Đọc các cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Đồ thị có hướng chỉ thêm 1 chiều
    }
    
    int result = shortestPath(adj, n, X, Y);
    cout << result << endl;
    
    return 0;
}