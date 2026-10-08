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
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "--" << endl;
    }

    int getId() const {
        return id;
    }
};

int main() {
    vector<Student> students;

    students.push_back(Student(1, "Mawra Nawaz", "Software Engineering", 3.5));
    students.push_back(Student(2, "Ali Khan", "Computer Science", 3.2));

    cout << "Student Management System" << endl << endl;

    for (const Student& student : students) {
        student.display();
    }

    return 0;
}
