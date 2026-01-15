#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void addBeginning(int x);
void addAfter(int after, int x);
void addEnd(int x);

int main() {
    addBeginning(5); addBeginning(4);
    addEnd(6); addEnd(7); addEnd(9);
    addAfter(7, 8);
    Node* tmp = head;
    while(tmp->next) {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << tmp->data << endl;
}

void addBeginning(int x) {
    Node* tmp = new Node();
    tmp->data = x;
    tmp->next = head;
    head = tmp;
}

void addAfter(int after, int x) {
    Node* ptr = head;
    while (ptr && ptr->data != after) ptr = ptr->next;
    if(!ptr) return;
    Node* tmp = new Node();
    tmp->data = x;
    tmp->next = ptr->next;
    ptr->next = tmp;
}

void addEnd(int x) {
    Node* tmp = new Node();
    tmp->data = x;
    tmp->next = nullptr;
    Node* ptr = head;
    while(ptr->next) ptr = ptr->next;
    ptr->next = tmp;
}