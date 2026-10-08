#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int id;
    string name;
    string department;
    float cgpa;

public:

    void addStudent()
    {
        cout << "\nEnter Student ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void displayStudent()
    {
        cout << "\n-----------" << endl;
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "------------" << endl;
    }

    int getId()
    {
        return id;
    }

    void updateStudent()
    {
        cin.ignore();

        cout << "\nEnter New Student Name: ";
        getline(cin, name);

        cout << "Enter New Department: ";
        getline(cin, department);

        cout << "Enter New CGPA: ";
        cin >> cgpa;

        cout << "\nStudent record updated successfully!" << endl;
    }
};


int main()
{
    Student students[50];

    int totalStudents = 0;
    int choice;
    int searchId;
    int found;

    do
    {
        cout << "\n=================================" << endl;
        cout << "     STUDENT MANAGEMENT SYSTEM" << endl;
        cout << "=================================" << endl;

        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;


        // ADD STUDENT
        if (choice == 1)
        {
            if (totalStudents < 50)
            {
                students[totalStudents].addStudent();

                totalStudents++;

                cout << "\nStudent added successfully!" << endl;
            }
            else
            {
                cout << "\nStudent limit reached!" << endl;
            }
        }


        // DISPLAY STUDENTS
        else if (choice == 2)
        {
            if (totalStudents == 0)
            {
                cout << "\nNo student records available." << endl;
            }
            else
            {
                cout << "\n ALL STUDENT RECORDS" << endl;

                for (int i = 0; i < totalStudents; i++)
                {
                    students[i].displayStudent();
                }
            }
        }


        // SEARCH STUDENT
        else if (choice == 3)
        {
            cout << "\nEnter Student ID to search: ";
            cin >> searchId;

            found = 0;

            for (int i = 0; i < totalStudents; i++)
            {
                if (students[i].getId() == searchId)
                {
                    cout << "\nStudent found!" << endl;

                    students[i].displayStudent();

                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                cout << "\nStudent not found." << endl;
            }
        }


        // UPDATE STUDENT
        else if (choice == 4)
        {
            cout << "\nEnter Student ID to update: ";
            cin >> searchId;

            found = 0;

            for (int i = 0; i < totalStudents; i++)
            {
                if (students[i].getId() == searchId)
                {
                    students[i].updateStudent();

                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                cout << "\nStudent not found." << endl;
            }
        }


        // DELETE STUDENT
        else if (choice == 5)
        {
            cout << "\nEnter Student ID to delete: ";
            cin >> searchId;

            found = 0;

            for (int i = 0; i < totalStudents; i++)
            {
                if (students[i].getId() == searchId)
                {
                    for (int j = i; j < totalStudents - 1; j++)
                    {
                        students[j] = students[j + 1];
                    }

                    totalStudents--;

                    found = 1;

                    cout << "\nStudent deleted successfully!" << endl;

                    break;
                }
            }

            if (found == 0)
            {
                cout << "\nStudent not found." << endl;
            }
        }


        // EXIT
        else if (choice == 6)
        {
            cout << "\nThank you for using Student Management System!" << endl;
        }


        // INVALID CHOICE
        else
        {
            cout << "\nInvalid choice! Please try again." << endl;
        }

    }
    while (choice != 6);


    return 0;
}



       
     

