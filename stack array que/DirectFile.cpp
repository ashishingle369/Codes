#include <iostream>
#include <fstream>
using namespace std;

// Class for Student
class Student {
    int rollNo;
    char name[50];
    int age;
    float cgpa;

public:
    void inputDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, 50);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void displayDetails() const {
        cout << "Roll Number: " << rollNo << "\nName: " << name << "\nAge: " << age << "\nCGPA: " << cgpa << "\n";
    }

    int getRollNo() const { return rollNo; }
};

// Function to add student details (Direct Access)
void addStudentDirect() {
    Student s;
    ofstream outFile("students_direct.dat", ios::app | ios::binary);
    cout << "\nAdd Student:\n";
    s.inputDetails();
    outFile.write(reinterpret_cast<char*>(&s), sizeof(s));
    outFile.close();
    cout << "Student added successfully!\n";
}

// Function to search student by Roll Number (Direct Access)
void searchStudentDirect() {
    int rollNo;
    Student s;
    ifstream inFile("students_direct.dat", ios::in | ios::binary);
    if (!inFile) {
        cout << "No records found!\n";
        return;
    }
    cout << "\nEnter Roll Number to Search: ";
    cin >> rollNo;

    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.getRollNo() == rollNo) {
            cout << "\nStudent Found:\n";
            s.displayDetails();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with Roll Number " << rollNo << " not found.\n";
    }
    inFile.close();
}

// Function to delete student by Roll Number (Direct Access)
void deleteStudentDirect() {
    int rollNo;
    Student s;
    ifstream inFile("students_direct.dat", ios::in | ios::binary);
    ofstream outFile("temp.dat", ios::out | ios::binary);

    if (!inFile) {
        cout << "No records found!\n";
        return;
    }

    cout << "\nEnter Roll Number to Delete: ";
    cin >> rollNo;

    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.getRollNo() == rollNo) {
            found = true;
            cout << "Student with Roll Number " << rollNo << " has been deleted.\n";
        } else {
            outFile.write(reinterpret_cast<char*>(&s), sizeof(s));
        }
    }

    if (!found) {
        cout << "Student with Roll Number " << rollNo << " not found.\n";
    }

    inFile.close();
    outFile.close();

    // Replace original file with the updated file
    remove("students_direct.dat");
    rename("temp.dat", "students_direct.dat");
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student (Direct Access)"
             << "\n2. Search Student (Direct Access)"
             << "\n3. Delete Student (Direct Access)"
             << "\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudentDirect();
                break;
            case 2:
                searchStudentDirect();
                break;
            case 3:
                deleteStudentDirect();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}
