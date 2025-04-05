#include <iostream>
using namespace std;

// Cấu trúc một node trong cây BST
struct Node {
    int data;        
    Node* left;      
    Node* right;     
   
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Hàm chèn một giá trị vào cây BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);  // Nếu cây rỗng, tạo node mới
    if (val < root->data)             // Nếu giá trị nhỏ hơn node hiện tại
        root->left = insert(root->left, val);  // Chèn vào cây con bên trái
    else  
        root->right = insert(root->right, val); // Chèn vào cây con bên phải
    return root;
}

// Hàm tìm node có giá trị nhỏ nhất trong cây (hỗ trợ khi xóa node)
Node* findMin(Node* root) {
    while (root->left) root = root->left; // Đi hết bên trái để tìm node nhỏ nhất
    return root;
}

// Hàm xóa một phần tử trong BST
Node* deleteNode(Node* root, int val) {
    if (!root) return root;  // Nếu cây rỗng, trả về null

    if (val < root->data)  // Nếu giá trị cần xóa nhỏ hơn node hiện tại
        root->left = deleteNode(root->left, val);  // Tìm trong cây con bên trái
    else if (val > root->data)  // Nếu giá trị cần xóa lớn hơn node hiện tại
        root->right = deleteNode(root->right, val); // Tìm trong cây con bên phải
    else {
        // Trường hợp node có tối đa một con hoặc không có con
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        // Trường hợp node có hai con: tìm node nhỏ nhất bên phải
        Node* temp = findMin(root->right);
        root->data = temp->data;  // Thay thế giá trị của node cần xóa
        root->right = deleteNode(root->right, temp->data); // Xóa node nhỏ nhất bên phải
    }
    return root;
}

// Hàm duyệt cây theo thứ tự trung tố (Inorder Traversal)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);        // Duyệt cây con bên trái
    cout << root->data << " ";  // In giá trị của node hiện tại
    inorder(root->right);       // Duyệt cây con bên phải
}

int main() {
    Node* root = nullptr;

    // Danh sách số ban đầu để tạo BST
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int val : values) root = insert(root, val); // Chèn từng phần tử vào cây

    cout << "BST sau khi tạo: ";
    inorder(root);  // In cây theo thứ tự trung tố
    cout << endl;

    // Chèn thêm các giá trị mới vào BST
    root = insert(root, 14);
    root = insert(root, 0);
    root = insert(root, 35);
    cout << "BST sau khi chèn 14, 0, 35: ";
    inorder(root);
    cout << endl;

    // Xóa các phần tử trong BST
    root = deleteNode(root, 6);
    root = deleteNode(root, 13);
    root = deleteNode(root, 35);
    cout << "BST sau khi xóa 6, 13, 35: ";
    inorder(root);
    cout << endl;

    return 0;
}