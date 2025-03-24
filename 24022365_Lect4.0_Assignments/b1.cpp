#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void append(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        printList();
    }
    void search(int x) {
        Node* current = head;
        int position = 1;
        bool found = false;
        while (current != nullptr) {
            if (current->data == x) {
                found = true;
                cout << position << endl;
                break;
            }
            current = current->next;
            position++;
        }
        if (!found) {
            cout << "NO" << endl;
        }
    }
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        tail = head;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " ";
            current = current->next;
        }
        cout << endl;
    }
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};
int main() {
    LinkedList list;
    int n;
    cin >> n; 
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "append") {
            int x;
            cin >> x;
            list.append(x);
        } else if (command == "search") {
            int x;
            cin >> x;
            list.search(x);
        } else if (command == "reverse") {
            list.reverse();
        }
    }
    return 0;
}
