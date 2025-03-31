#include <iostream>
#include <map>
#include <set>
using namespace std;

class Tree {
private:
    map<int, set<int>> tree; // Cấu trúc lưu danh sách kề
    int root; // Gốc của cây

public:
    // Hàm khởi tạo cây từ đầu vào
    Tree(int N, int M) {
        set<int> nodes, children; // Tập hợp các nút và các nút có cha
        
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].insert(v); // Thêm cạnh từ u -> v
            nodes.insert(u);
            nodes.insert(v);
            children.insert(v);
        }
        
        // Xác định gốc cây (nút không có cha)
        for (int node : nodes) {
            if (children.find(node) == children.end()) {
                root = node;
                break;
            }
        }
    }

    // Tính chiều cao của cây bằng đệ quy
    int height(int node) {
        int maxH = 0;
        for (int child : tree[node]) {
            maxH = max(maxH, height(child));
        }
        return maxH + 1;
    }

    // Duyệt cây theo thứ tự trước (preorder traversal)
    void preorder(int node) {
        cout << node << " ";
        for (int child : tree[node]) {
            preorder(child);
        }
    }

    // Duyệt cây theo thứ tự sau (postorder traversal)
    void postorder(int node) {
        for (int child : tree[node]) {
            postorder(child);
        }
        cout << node << " ";
    }

    // Kiểm tra xem cây có phải cây nhị phân không
    bool isBinaryTree() {
        for (auto &p : tree) {
            if (p.second.size() > 2) return false;
        }
        return true;
    }

    // Duyệt cây theo thứ tự giữa (inorder traversal) nếu là cây nhị phân
    void inorder(int node) {
        if (tree[node].size() > 2) {
            cout << "NOT BINARY TREE";
            return;
        }
        auto it = tree[node].begin();
        if (it != tree[node].end()) {
            inorder(*it);
            it++;
        }
        cout << node << " ";
        if (it != tree[node].end()) {
            inorder(*it);
        }
    }

    // Xuất kết quả theo yêu cầu
    void printResults() {
        cout << height(root) - 1 << endl;
        preorder(root);
        cout << endl;
        postorder(root);
        cout << endl;
        if (isBinaryTree()) {
            inorder(root);
        } else {
            cout << "NOT BINARY TREE";
        }
        cout << endl;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    Tree tree(N, M);
    tree.printResults();
    return 0;
}
