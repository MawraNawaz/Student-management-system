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

    int getId() const {
        return id;
    }

    void display() const {
        cout << "\n---" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "------------------------" << endl;
    }

    void update() {
        cin.ignore();

        cout << "Enter new name: ";
        getline(cin, name);

        cout << "Enter new department: ";
        getline(cin, department);

        cout << "Enter new CGPA: ";
        cin >> cgpa;

        cout << "\nStudent record updated successfully!" << endl;
    }
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n Student Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student by ID" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {

            int id;
            string name, department;
            float cgpa;

            cout << "\nEnter Student ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Student Name: ";
            getline(cin, name);

            cout << "Enter Department: ";
            getline(cin, department);

            cout << "Enter CGPA: ";
            cin >> cgpa;

            students.push_back(
                Student(id, name, department, cgpa)
            );

            cout << "\nStudent added successfully!" << endl;
        }

        else if (choice == 2) {

            if (students.empty()) {
                cout << "\nNo students available." << endl;
            }
            else {
                cout << "\n Student Record" << endl;

                for (const Student& student : students) {
                    student.display();
                }
            }
        }

        else if (choice == 3) {

            int searchId;
            bool found = false;

            cout << "\nEnter Student ID to search: ";
            cin >> searchId;

            for (const Student& student : students) {

                if (student.getId() == searchId) {
                    cout << "\nStudent Found!" << endl;
                    student.display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nStudent not found." << endl;
            }
        }

        else if (choice == 4) {

            int updateId;
            bool found = false;

            cout << "\nEnter Student ID to update: ";
            cin >> updateId;

            for (Student& student : students) {

                if (student.getId() == updateId) {
                    student.update();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nStudent not found." << endl;
            }
        }

        else if (choice == 5) {

            int deleteId;
            bool found = false;

            cout << "\nEnter Student ID to delete: ";
            cin >> deleteId;

            for (auto it = students.begin(); it != students.end(); ++it) {

                if (it->getId() == deleteId) {
                    students.erase(it);
                    cout << "\nStudent deleted successfully!" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nStudent not found." << endl;
            }
        }

        else if (choice == 6) {

            cout << "\nThank you for using Student Management System!" << endl;
        }

        else {

            cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}

       
     

