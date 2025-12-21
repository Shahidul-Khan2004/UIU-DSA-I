#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = nullptr;

Node* createNode(int value);
void addStart(Node* node);
void printLinkedList();
void freeLinkedList();
void reverseLinkedList();

int main(void){
    cout<<"How many nodes do you want?"<<endl;
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        int val; cout<<"Data in node "<<i+1<<": "; cin >> val;
        Node* newNode = createNode(val);
        addStart(newNode);
    }
    printLinkedList();
    reverseLinkedList();
    printLinkedList();
    freeLinkedList();
    printLinkedList();
}

Node* createNode(int value){
    Node* temp = new Node();
    temp->data = value;
    temp->next = nullptr;
    return temp;
}

void addStart(Node* node){
    if (head != nullptr) node->next = head;
    head = node;
}

void printLinkedList(){
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* ptr = head;
    while (ptr->next != nullptr){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<ptr->data<<endl;
}

void freeLinkedList(){
    Node* ptr = head;
    while(ptr->next != nullptr){
        Node* ptrPrev = ptr;
        ptr = ptr->next;
        delete ptrPrev;
    }
    delete ptr;
    head = nullptr;
}

void reverseLinkedList() {
    Node* prev = nullptr; Node* curr = head; Node* next = nullptr;
    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}