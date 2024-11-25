#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Class for Student
class Student {
    public:
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

// Function to add student details (Sequential Access)
void addStudentSequential() {
    Student s;
    ofstream outFile("students_sequential.txt", ios::app);
    cout << "\nAdd Student:\n";
    s.inputDetails();
    outFile << s.getRollNo() << " " << s.name << " " << s.age << " " << s.cgpa << "\n";
    outFile.close();
    cout << "Student added successfully!\n";
}

// Function to search student by Roll Number (Sequential Access)
void searchStudentSequential() {
    int rollNo;
    Student s;
    ifstream inFile("students_sequential.txt");
    if (!inFile) {
        cout << "No records found!\n";
        return;
    }
    cout << "\nEnter Roll Number to Search: ";
    cin >> rollNo;

    bool found = false;
    while (inFile >> s.rollNo >> s.name >> s.age >> s.cgpa) {
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

void deleteStudentSequential() {
    int rollNo;
    Student s;
    ifstream inFile("students_sequential.txt");
    ofstream outFile("temp.txt");

    if (!inFile) {
        cout << "No records found!\n";
        return;
    }

    cout << "\nEnter Roll Number to Delete: ";
    cin >> rollNo;

    bool found = false;
    while (inFile >> s.rollNo >> s.name >> s.age >> s.cgpa) {
        if (s.getRollNo() == rollNo) {
            found = true;
            cout << "Student with Roll Number " << rollNo << " has been deleted.\n";
        } else {
            outFile << s.getRollNo() << " " << s.name << " " << s.age << " " << s.cgpa << "\n";
        }
    }
    inFile.close();
    outFile.close();

    if (!found) {
        cout << "Student with Roll Number " << rollNo << " not found.\n";
    }

    // Replace the original file with the updated file
    remove("students_sequential.txt");
    rename("temp.txt", "students_sequential.txt");
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student (Sequential Access)\n2. Search Student (Sequential Access)\n3. Delete\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudentSequential();
                break;
            case 2:
                searchStudentSequential();
                break;
            case 3:
                deleteStudentSequential();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);
    return 0;
}
