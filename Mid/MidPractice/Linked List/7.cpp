#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverseList(Node* head) {
    
    if(!head || !head->next) return head;

    Node* ptr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while(ptr) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    return prev;
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
    // Create a list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};
    
    cout << "Original list: ";
    printList(head);
    
    head = reverseList(head);
    
    cout << "Reversed list: ";
    printList(head);
    
    return 0;
}
