#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int n, const vector<vector<int>>& adj, vector<int>& inDegree) {
    vector<int> result;
    queue<int> q;

    // Thêm tất cả các đỉnh có bậc vào bằng 0 vào hàng đợi
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        // Duyệt qua các đỉnh kề và giảm bậc vào của chúng
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return result;
}

int main() {
    ifstream in("jobs.txt");
    ofstream out("jobs.out");

    int n, m;
    in >> n >> m;

    vector<vector<int>> adj(n + 1); // Danh sách kề
    vector<int> inDegree(n + 1, 0); // Bậc vào của các đỉnh

    // Đọc dữ liệu đầu vào và xây dựng đồ thị
    for (int i = 0; i < m; ++i) {
        int u, v;
        in >> v >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    // Thực hiện sắp xếp topo
    vector<int> sortedJobs = topologicalSort(n, adj, inDegree);

    // Ghi kết quả ra file
    for (size_t i = 0; i < sortedJobs.size(); ++i) {
        if (i > 0) out << " ";
        out << sortedJobs[i];
    }

    return 0;
}