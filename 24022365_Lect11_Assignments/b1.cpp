#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX / 2; // Tránh tràn số khi cộng

// Hàm Bellman-Ford để tìm đường đi ngắn nhất từ một nguồn
vector<int> bellmanFord(int n, const vector<vector<pair<int, int>>>& adj, int s, vector<int>& prev) {
    vector<int> dist(n + 1, INF);
    dist[s] = 0;
    prev.assign(n + 1, -1);

    // Lặp n-1 lần
    for (int i = 1; i <= n - 1; ++i) {
        for (int u = 1; u <= n; ++u) {
            if (dist[u] == INF) continue;
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    prev[v] = u;
                }
            }
        }
    }

    return dist;
}

int main() {
    ifstream in("dirty.txt");
    ofstream out("dirty.out");

    int n, m, s, e;
    in >> n >> m >> s >> e;

    // Khởi tạo đồ thị dạng danh sách kề
    vector<vector<pair<int, int>>> adj(n + 1);

    // Đọc dữ liệu đầu vào
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        in >> u >> v >> d;
        adj[u].emplace_back(v, d);
    }

    //a
    vector<int> prev;
    vector<int> dist_s = bellmanFord(n, adj, s, prev);

    // Ghi kết quả đường đi từ s đến e
    out << dist_s[e] << endl;

    // Truy vết đường đi
    vector<int> path;
    for (int v = e; v != -1; v = prev[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0) out << " ";
        out << path[i];
    }
    out << endl;

    //b
    vector<vector<int>> allDist(n + 1, vector<int>(n + 1, INF));

    // Chạy Bellman-Ford cho mỗi đỉnh nguồn
    for (int source = 1; source <= n; ++source) {
        vector<int> temp_prev; // Không cần dùng prev ở đây
        vector<int> dist = bellmanFord(n, adj, source, temp_prev);
        
        // Sao chép kết quả vào ma trận allDist
        for (int dest = 1; dest <= n; ++dest) {
            allDist[source][dest] = dist[dest];
        }
    }

    // Ghi ma trận kết quả
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j > 1) out << " ";
            if (allDist[i][j] == INF) out << "INF";
            else out << allDist[i][j];
        }
        out << endl;
    }

    in.close();
    out.close();
    return 0;
}