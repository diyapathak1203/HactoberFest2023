#include <iostream>
using namespace std;

// Definition of a node in a linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a linked list
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;  // Save the next node
        current->next = prev;  // Reverse the link
        
        // Move one step forward in the list
        prev = current;
        current = next;
    }
    
    return prev; // New head of the reversed list
}

// Function to print a linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    cout << "Original Linked List: ";
    printList(head);
    
    head = reverseLinkedList(head);
    
    cout << "Reversed Linked List: ";
    printList(head);
    
    // Clean up memory (optional)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
