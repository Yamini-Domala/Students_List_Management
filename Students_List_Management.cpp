#include <bits/stdc++.h>
using namespace std;

#define MAX_STUDENTS 50

class Student {
public:
    char name[30];
    int id;
    int age;
    float gpa;
};

Student students[MAX_STUDENTS];
int num_students = 0;

void clearScreen() {
    system("cls"); // On Windows. For Unix-like systems, use "clear"
}

void loadRecords() {
    ifstream file("students.txt");
    if (file.is_open()) {
        while (file >> students[num_students].id >> students[num_students].name >> students[num_students].age >> students[num_students].gpa) {
            num_students++;
        }
        file.close();
    }
}

void saveRecords() {
    ofstream file("students.txt");
    for (int i = 0; i < num_students; i++) {
        file << students[i].id << " " << students[i].name << " " << students[i].age << " " << students[i].gpa << endl;
    }
    file.close();
}

void addStudent() {
    if (num_students >= MAX_STUDENTS) {
        cout << "Cannot add more students. Max limit reached." << endl;
        return;
    }

    Student newStudent;
    cout << "Enter Student ID: ";
    cin >> newStudent.id;
    cout << "Enter Student Name: ";
    cin.ignore();
    cin.getline(newStudent.name, 30);
    cout << "Enter Student Age: ";
    cin >> newStudent.age;
    cout << "Enter Student GPA: ";
    cin >> newStudent.gpa;

    students[num_students] = newStudent;
    num_students++;
    saveRecords();
    cout << "Student added successfully!" << endl;
}

void editStudent() {
    int id;
    cout << "Enter Student ID to edit: ";
    cin >> id;

    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            cout << "Enter new name: ";
            cin.ignore();
            cin.getline(students[i].name, 30);
            cout << "Enter new age: ";
            cin >> students[i].age;
            cout << "Enter new GPA: ";
            cin >> students[i].gpa;
            saveRecords();
            cout << "Student record updated successfully!" << endl;
            return;
        }
    }
    cout << "Student ID not found!" << endl;
}

void deleteStudent() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            saveRecords();
            cout << "Student record deleted successfully!" << endl;
            return;
        }
    }
    cout << "Student ID not found!" << endl;
}

void searchStudent() {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "GPA: " << students[i].gpa << endl;
            cout << "Press 'r' to return to the menu...";
            char returnOption;
            while (true) {
                cin >> returnOption;
                if (returnOption == 'r' || returnOption == 'R') {
                    break;
                }
            }
            return;
        }
    }
    cout << "Student ID not found!" << endl;
    cout << "Press 'r' to return to the menu...";
    char returnOption;
    while (true) {
        cin >> returnOption;
        if (returnOption == 'r' || returnOption == 'R') {
            break;
        }
    }
}

void listStudents() {
    if (num_students == 0) {
        cout << "No student records found!" << endl;
        return;
    }

    cout << "List of Students:" << endl;
    for (int i = 0; i < num_students; i++) {
        cout << "ID: " << students[i].id << ", Name: " << students[i].name << ", Age: " << students[i].age << ", GPA: " << students[i].gpa << endl;
    }

    cout << "Press 'r' to return to the menu...";
    char returnOption;
    while (true) {
        cin >> returnOption;
        if (returnOption == 'r' || returnOption == 'R') {
            break;
        }
    }
}

void menu() {
    clearScreen();
    cout << "***** Student Management System *****" << endl;
    cout << endl;
    cout << "1.  Add New Student" << endl;
    cout << "2.  Edit Student Record" << endl;
    cout << "3.  Delete Student Record" << endl;
    cout << "4.  Search Student Record" << endl;
    cout << "5.  List All Students" << endl;
    cout << "6.  Quit" << endl;
    cout << endl;
    cout << "Select an option: ";
}

int main() {
    loadRecords();

    char choice;
    while (true) {
        menu();
        cin >> choice;
        switch (choice) {
            case '1':
                addStudent();
                break;
            case '2':
                editStudent();
                break;
            case '3':
                deleteStudent();
                break;
            case '4':
                searchStudent();
                break;
            case '5':
                listStudents();
                break;
            case '6':
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }

    return 0;
}
