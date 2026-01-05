#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head;

int main() {
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();

    node1->data = 1; node2->data = 2; node3->data = 3;
    node1->next = node2; node2->next = node3; node3->next = nullptr;

    head = node1;

    int sum = 0;
    
    Node* ptr = head;
    while(ptr) {
        sum += ptr->data;
        ptr = ptr->next;
    }
    cout << sum << endl;
}