#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

Node* createNode(int value);
void addStart(Node* node);
void addEnd(Node* node);
void searchAndDelete(int value);
void printLinkedList();
void freeLinkedList();
void reverseLinkedList();

int main() {
    cout<<"How many nodes do you want?"<<endl;
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        int val; cout<<"Data in node "<<i+1<<": "; cin >> val;
        Node* newNode = createNode(val);
        addStart(newNode);
    }
}

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void addStart(Node* node) {
    if(head == nullptr) {
        head = node;
        tail = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}

void addEnd(Node* node) {
    if(head == nullptr) {
        head = node;
        tail = node;
        return;
    }
    node->prev = tail;
    tail->next = node;
    tail = node;
}

void searchAndDelete(int value) {
    if(head == nullptr) return;
    
    Node* tmp = head;
    while(tmp && tmp->data != value) {
        tmp = tmp->next;
    }
    if (tmp == nullptr) {
        cout << "not found" << endl;
        return;
    }
    if(tmp->prev == nullptr) head = tmp->next;
    else tmp->prev->next = tmp->next;

    if(tmp->next == nullptr) tail = tmp->prev;
    else tmp->next->prev = tmp->prev;

    delete tmp;
}