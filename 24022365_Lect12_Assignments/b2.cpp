#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, d;
};

// Hàm so sánh để sắp xếp các cạnh theo trọng số tăng dần
bool compareEdges(const Edge& a, const Edge& b) {
    return a.d < b.d;
}

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        
        if (rootU != rootV) {
            // Union by rank
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

int main() {
    ifstream in("connection.txt");
    ofstream out("connection.out");

    int n, m;
    in >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        in >> edges[i].u >> edges[i].v >> edges[i].d;
    }

    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), compareEdges);

    UnionFind uf(n);
    vector<Edge> mstEdges;
    int totalCost = 0;

    // Thuật toán Kruskal
    for (const Edge& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unionSets(edge.u, edge.v);
            mstEdges.push_back(edge);
            totalCost += edge.d;
            
            // Dừng khi đã chọn đủ n-1 cạnh
            if (mstEdges.size() == n - 1) {
                break;
            }
        }
    }

    out << totalCost << endl;
    for (const Edge& edge : mstEdges) {
        out << edge.u << " " << edge.v << " " << edge.d << endl;
    }

    return 0;
}