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
void delHead();
void del(int pos);
void delEnd();

int main() {
    addBeginning(5); addBeginning(4);
    addEnd(6); addEnd(7); addEnd(9);
    addAfter(7, 8);
    delHead(); del(3); delEnd();
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
void delHead() {
    Node* tmp = head;
    head = tmp->next;
    delete tmp;
}
void del(int pos) {
    Node* tmp = head;
    Node* prev = nullptr;
    for(int i = 0; i < pos; i++) {
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = tmp->next;
    tmp->next = nullptr;
    delete tmp;

}
void delEnd() {
    Node* tmp = head;
    Node* prev = nullptr;
    while(tmp->next) {
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = nullptr;
    delete tmp;
}