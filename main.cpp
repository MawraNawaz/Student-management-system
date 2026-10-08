#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    string department;
    float cgpa;

public:
    Student(int studentId, string studentName, string studentDepartment, float studentCgpa) {
        id = studentId;
        name = studentName;
        department = studentDepartment;
        cgpa = studentCgpa;
    }

    void display() const {
        cout << "\nID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n Student Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name, department;
            float cgpa;

            cout << "Enter Student ID: ";
            cin >> id;

            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, name);

            cout << "Enter Department: ";
            getline(cin, department);

            cout << "Enter CGPA: ";
            cin >> cgpa;

            students.push_back(Student(id, name, department, cgpa));

            cout << "\nStudent added successfully!" << endl;
        }

        else if (choice == 2) {
            if (students.empty()) {
                cout << "\nNo students available." << endl;
            } else {
                // cout << "\n *Student Record*" << endl;

                for (const Student& student : students) {
                    student.display();
                }
            }
        }

        else if (choice == 3) {
            cout << "\nThank you for using the system!" << endl;
        }

        else {
            cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
