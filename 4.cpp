#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Floyd's Cycle Detection Algorithm (Tortoise and Hare)
bool hasCycle(Node* head) {
    if (!head || !head->next) return false;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;  // Cycle detected
        }
    }
    
    return false;  // No cycle
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};
    
    // Test without cycle
    cout << "List without cycle: " << (hasCycle(head) ? "Has cycle" : "No cycle") << endl;
    
    // Create a cycle: 5 -> 3 (point last node to third node)
    head->next->next->next->next->next = head->next->next;
    
    // Test with cycle
    cout << "List with cycle: " << (hasCycle(head) ? "Has cycle" : "No cycle") << endl;
    
    return 0;
}
