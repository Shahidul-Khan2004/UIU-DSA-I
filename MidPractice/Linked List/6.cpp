#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isPalindrome(Node* head) {
    if(!head->next) return true;
    Node* slow = head;
    Node* slowPrev = nullptr;
    Node* fast = head;
    while(fast && fast->next) {
        slowPrev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    slowPrev->next = nullptr;
    Node* ptrPrev = nullptr;
    Node* ptr = slow;
    Node* ptrNext = nullptr;
    while(ptr) {
        ptrNext = ptr->next;
        ptr->next = ptrPrev;
        ptrPrev = ptr;
        ptr = ptrNext;
    }
    ptr = ptrPrev;
    Node* tmp = head;
    while(tmp) {
        if(tmp->data != ptr->data) return false;
        tmp = tmp->next;
        ptr = ptr->next;
    }
    return true;
}

int main() {
    // Test case 1: Palindrome list (1 -> 2 -> 3 -> 2 -> 1)
    Node* head1 = new Node{1, nullptr};
    head1->next = new Node{2, nullptr};
    head1->next->next = new Node{3, nullptr};
    head1->next->next->next = new Node{2, nullptr};
    head1->next->next->next->next = new Node{1, nullptr};
    
    cout << "List 1 (1 -> 2 -> 3 -> 2 -> 1): " 
         << (isPalindrome(head1) ? "Palindrome" : "Not palindrome") << endl;
    
    // Test case 2: Not palindrome (1 -> 2 -> 3 -> 4)
    Node* head2 = new Node{1, nullptr};
    head2->next = new Node{2, nullptr};
    head2->next->next = new Node{3, nullptr};
    head2->next->next->next = new Node{4, nullptr};
    
    cout << "List 2 (1 -> 2 -> 3 -> 4): " 
         << (isPalindrome(head2) ? "Palindrome" : "Not palindrome") << endl;
    
    // Test case 3: Palindrome even length (1 -> 2 -> 2 -> 1)
    Node* head3 = new Node{1, nullptr};
    head3->next = new Node{2, nullptr};
    head3->next->next = new Node{2, nullptr};
    head3->next->next->next = new Node{1, nullptr};
    
    cout << "List 3 (1 -> 2 -> 2 -> 1): " 
         << (isPalindrome(head3) ? "Palindrome" : "Not palindrome") << endl;
    
    // Test case 4: Single element
    Node* head4 = new Node{5, nullptr};
    cout << "List 4 (5): " 
         << (isPalindrome(head4) ? "Palindrome" : "Not palindrome") << endl;
    
    return 0;
}
