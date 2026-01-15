#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isSorted(Node* head) {
    if (!head || !head->next) return true;
    
    Node* current = head;
    
    while (current->next) {
        if (current->data > current->next->data) {
            return false;  // Not sorted (found a decreasing pair)
        }
        current = current->next;
    }
    
    return true;  // Sorted in non-decreasing order
}

int main() {
    // Create a sorted list: 1 -> 2 -> 3 -> 5 -> 5 -> 7
    Node* head1 = new Node{1, nullptr};
    head1->next = new Node{2, nullptr};
    head1->next->next = new Node{3, nullptr};
    head1->next->next->next = new Node{5, nullptr};
    head1->next->next->next->next = new Node{5, nullptr};
    head1->next->next->next->next->next = new Node{7, nullptr};
    
    cout << "List 1 (1 -> 2 -> 3 -> 5 -> 5 -> 7): " 
         << (isSorted(head1) ? "Sorted" : "Not sorted") << endl;
    
    // Create an unsorted list: 1 -> 3 -> 2 -> 5
    Node* head2 = new Node{1, nullptr};
    head2->next = new Node{3, nullptr};
    head2->next->next = new Node{2, nullptr};
    head2->next->next->next = new Node{5, nullptr};
    
    cout << "List 2 (1 -> 3 -> 2 -> 5): " 
         << (isSorted(head2) ? "Sorted" : "Not sorted") << endl;
    
    // Create a single element list
    Node* head3 = new Node{42, nullptr};
    cout << "List 3 (42): " 
         << (isSorted(head3) ? "Sorted" : "Not sorted") << endl;
    
    // Empty list
    Node* head4 = nullptr;
    cout << "List 4 (empty): " 
         << (isSorted(head4) ? "Sorted" : "Not sorted") << endl;
    
    return 0;
}
