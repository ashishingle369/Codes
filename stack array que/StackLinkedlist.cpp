#include <iostream>
#include <string>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Stack class using linked list
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL; // Initialize the stack as empty
    }

    // Create stack (already initialized in constructor)
    void create() {
        top = NULL;
        cout << "Stack created." << endl;
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        if (top == NULL) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
        } else {
            Node* temp = top;
            cout << "Popped " << top->data << " from the stack." << endl;
            top = top->next;
            delete temp;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        if (top == NULL) {
            return true;
        } else {
            return false;
        }
    }

    // Display the elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            Node* temp = top;
            cout << "Stack elements are: ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

// Function to check if a string is a palindrome
bool isPalindrome(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false; // If characters at start and end are not equal, it's not a palindrome
        }
        start++;
        end--;
    }
    return true; // If all characters match, it's a palindrome
}

int main() {
    Stack s;
    int choice, value;
    string str;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create Stack\n";
        cout << "2. Push Element\n";
        cout << "3. Pop Element\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Display Stack\n";
        cout << "6. Check if String is Palindrome\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.create(); // Create the stack
                break;

            case 2:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value); // Push the element onto the stack
                break;

            case 3:
                s.pop(); // Pop the top element from the stack
                break;

            case 4:
                if (s.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;

            case 5:
                s.display(); // Display the stack elements
                break;

            case 6:
                cout << "Enter a string to check if it is a palindrome: ";
                cin >> str;
                if (isPalindrome(str)) {
                    cout << str << " is a palindrome." << endl;
                } else {
                    cout << str << " is not a palindrome." << endl;
                }
                break;

            case 7:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}
