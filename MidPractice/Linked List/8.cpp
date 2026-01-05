#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertSorted(Node* head, int x) {
    Node* newNode = new Node{x, nullptr};
    
    // If list is empty or x should be at the beginning
    if (!head || head->data >= x) {
        newNode->next = head;
        return newNode;
    }
    
    // Find the position to insert
    Node* current = head;
    while (current->next && current->next->data < x) {
        current = current->next;
    }
    
    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
    
    return head;
}

void printList(Node* head) {
    Node* tmp = head;
    while (tmp) {
        cout << tmp->data;
        if (tmp->next) cout << " -> ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    // Create a sorted list: 1 -> 3 -> 5 -> 7 -> 9
    Node* head = new Node{1, nullptr};
    head->next = new Node{3, nullptr};
    head->next->next = new Node{5, nullptr};
    head->next->next->next = new Node{7, nullptr};
    head->next->next->next->next = new Node{9, nullptr};
    
    cout << "Original list: ";
    printList(head);
    
    // Insert 4 in the middle
    head = insertSorted(head, 4);
    cout << "After inserting 4: ";
    printList(head);
    
    // Insert 0 at the beginning
    head = insertSorted(head, 0);
    cout << "After inserting 0: ";
    printList(head);
    
    // Insert 10 at the end
    head = insertSorted(head, 10);
    cout << "After inserting 10: ";
    printList(head);
    
    // Insert 5 (duplicate)
    head = insertSorted(head, 5);
    cout << "After inserting 5: ";
    printList(head);
    
    return 0;
}
