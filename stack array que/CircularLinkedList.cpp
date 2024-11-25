#include <iostream> 
using namespace std; 
 
class Node { 
public: 
    int data; 
    Node* next; 
 
    Node(int data) { 
        this->data = data; 
        this->next = nullptr; 
    } 
}; 
 
class CircularLinkedList { 
private: 
    Node* tail; 
 
public: 
    CircularLinkedList() : tail(nullptr) {} 
 
    // Insert a new node at the end of the list 
    void insert(int data) { 
        Node* newNode = new Node(data); 
 
        if (tail == nullptr)  // List is empty 
        { 
            tail = newNode; 
            tail->next = tail; // Point to itself to make it circular 
        } else { 
            newNode->next = tail->next; // Link new node to head 
            tail->next = newNode;       // Link old tail to new node 
            tail = newNode;             // Update tail to the new node 
        } 
        cout << "Inserted: " << data << endl; 
    } 
 
    // Delete a node with a specific value 
    void deleteNode(int key) { 
        if (tail == nullptr) { 
            cout << "List is empty, deletion not possible." << endl; 
            return; 
        } 
 
        Node *current = tail->next, *prev = tail; 
 
        // Case when the node to delete is the only node 
        if (tail == tail->next && tail->data == key) { 
            delete tail; 
            tail = nullptr; 
            cout << "Deleted: " << key << endl; 
            return; 
        } 
 
        // Traverse the list to find the node to delete 
        do { 
            if (current->data == key) { 
                prev->next = current->next; 
 
                // If the node to be deleted is the tail node 
                if (current == tail) { 
                    tail = prev; 
                } 
 
                delete current; 
                cout << "Deleted: " << key << endl; 
                return; 
            } 
 
            prev = current; 
            current = current->next; 
        } while (current != tail->next); 
 
        cout << "Element " << key << " not found." << endl; 
    } 
 
    // Display the circular linked list 
    void display() { 
        if (tail == nullptr) { 
            cout << "List is empty." << endl; 
            return; 
        } 
 
        Node* current = tail->next; // Start from the head 
        do { 
            cout << current->data << " "; 
            current = current->next; 
        } while (current != tail->next); 
        cout << endl; 
    } 
}; 
 
int main() { 
    CircularLinkedList cll; 
    // Inserting elements 
    cll.insert(10); 
    cll.insert(20); 
    cll.insert(30); 
    cll.insert(40); 
 
    cout << "Circular Linked List: "; 
    cll.display(); 
 
    // Deleting elements 
    cll.deleteNode(20); 
    cout << "After deleting 20: "; 
    cll.display(); 
 
    cll.deleteNode(10); 
    cout << "After deleting 10: "; 
    cll.display(); 
 
    cll.deleteNode(40); 
    cout << "After deleting 40: "; 
    cll.display(); 
    return 0; 
}