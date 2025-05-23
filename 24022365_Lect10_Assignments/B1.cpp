#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Hàm BFS để duyệt qua tất cả các nút trong thành phần liên thông
void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // Duyệt qua tất cả các nút kề với nút hiện tại
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // Tạo danh sách kề cho đồ thị
    vector<vector<int>> adj(n + 1); // Sử dụng index từ 1 đến n
    vector<bool> visited(n + 1, false);
    
    // Đọc các cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Đồ thị vô hướng nên thêm cả 2 chiều
    }
    
    int components = 0;
    
    // Duyệt qua tất cả các nút để đếm thành phần liên thông
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            bfs(i, adj, visited);
            components++; // Mỗi lần BFS mới là một thành phần liên thông mới
        }
    }
    
    cout << components << endl;
    return 0;
}