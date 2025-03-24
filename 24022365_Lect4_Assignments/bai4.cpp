#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    string studentClass;
    Student* next;
};

class StudentManager {
private:
    Student* head;// Con trỏ đầu danh sách liên kết

public:
    StudentManager() : head(nullptr) {}
    
    void insert(int id, const string& name, const string& studentClass) {
        Student* newStudent = new Student{id, name, studentClass, head};
        head = newStudent;// Cập nhật con trỏ đầu danh sách
    }
    
    void remove(int id) {
        Student* current = head;
        Student* prev = nullptr;
        
        while (current != nullptr && current->id != id) {
            prev = current;
            current = current->next;
        }
        // Duyệt danh sách để tìm sinh viên có ID cần xóa
        if (current == nullptr) return;
        
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        
        delete current;
    }
    
    string infor(int id) {
        Student* current = head;
        while (current != nullptr) {
            if (current->id == id) {
                return current->name + "," + current->studentClass;
            }
            current = current->next;
        }
        return "NA,NA"; // Trả về giá trị mặc định nếu không tìm thấy sinh viên
    }
};

int main() {
    StudentManager manager;
    string command;
    
    while (getline(cin, command)) {
        if (command.substr(0, 6) == "Insert") {
            int id;
            size_t pos1 = command.find('(', 6);
            size_t pos2 = command.find(',', pos1);
            size_t pos3 = command.find(',', pos2 + 1);
            size_t pos4 = command.find(')', pos3);
            
            id = stoi(command.substr(pos1 + 1, pos2 - pos1 - 1));
            string name = command.substr(pos2 + 1, pos3 - pos2 - 1);
            string studentClass = command.substr(pos3 + 1, pos4 - pos3 - 1);
            
            manager.insert(id, name, studentClass);
        } 
        else if (command.substr(0, 6) == "Delete") {
            int id = stoi(command.substr(7, command.length() - 7));
            manager.remove(id);
        } 
        else if (command.substr(0, 5) == "Infor") {
            int id = stoi(command.substr(6, command.length() - 6));
            cout << manager.infor(id) << endl;
        }
    }
    return 0;
}
