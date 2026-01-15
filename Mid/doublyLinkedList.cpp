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
void addAfter(int value, int newVal);
void searchAndDelete(int value);
void printLinkedList();
void freeLinkedList();
void reverseLinkedList();

int main() {
    cout<<"How many nodes do you want?"<<endl;
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        int val; cout<<"Data in node "<<i+1<<": "; cin >> val;
        addStart(createNode(val));
    }
    printLinkedList();
    addEnd(createNode(6));
    printLinkedList();
    addAfter(3, 8);
    printLinkedList();
    searchAndDelete(2);
    printLinkedList();
    reverseLinkedList();
    printLinkedList();
    freeLinkedList();
    printLinkedList();
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

void addAfter(int value, int newVal) {
    Node* newN = createNode(newVal);
    Node* ptr = head;
    while (ptr && ptr->data != value) ptr = ptr->next;
    if (ptr == nullptr) {
        cout << "target value not found" << endl;
        return;
    }
    if (ptr->next == nullptr) {
        tail->next = newN;
        newN->prev = tail;
        tail = newN;
        return;
    }
    newN->next = ptr->next;
    ptr->next = newN;
    newN->prev = ptr;
    newN->next->prev = newN;
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

void printLinkedList() {
    Node* ptr = head;
    if (!ptr){ 
        cout << "it's empty" << endl;
        return;
    }
    while(ptr->next) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << ptr->data << endl;
}

void freeLinkedList() {
    Node* ptr = head;
    if (!ptr) {
        cout << "already empty" << endl;
        return;
    }
    while (ptr) {
        Node* tmp = ptr;
        ptr = ptr -> next;
        delete tmp;
    }
    head = nullptr;
    tail = nullptr;
}

void reverseLinkedList() {
    Node* tmp = nullptr;
    Node* curr = head;

    while (curr) {
        tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;
        curr = curr->prev;
    }

    tmp = head;
    head = tail;
    tail = tmp;
}