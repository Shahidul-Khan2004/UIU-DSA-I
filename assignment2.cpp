#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

Node* createNode(int val);
void insertBegin(int value);
void insertEnd(int value);
void insertAtMiddle(int targetValue, int newValue);
void deleteBegin();
void deleteEnd();
void deleteAtPosition(int targetValue);
int sumOfElements(Node* head);
Node* reverseList(Node* head);
bool isSorted(Node* head);

void printList(Node* head) {
    Node* t = head;
    while (t) {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL\n";
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);
    insertEnd(60);
    insertEnd(70);

    printList(head);

    insertBegin(5);
    insertAtMiddle(30, 99);
    deleteBegin();
    deleteEnd();
    deleteAtPosition(40);
    //check isSorted
    //deleteAtPosition(99);

    printList(head);

    cout << "Sum = " << sumOfElements(head) << endl;

    head = reverseList(head);
    printList(head);

    cout << "Sorted Desc? " << (isSorted(head) ? "Yes" : "No") << endl;

    return 0;
}

Node* createNode(int val){
    Node* tmp = new Node();
    tmp->data = val;
    tmp->next = nullptr;
    return tmp;
}

void insertBegin(int value){
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}
void insertEnd(int value){
    Node* newNode = createNode(value);
    if(!head) {
        head = newNode;
        return;
    }
    Node* ptr = head;
    while(ptr->next) ptr = ptr->next;
    ptr->next = newNode;
}
void insertAtMiddle(int targetValue, int newValue){
    Node* newNode = createNode(newValue);
    if(!head) {
        head = newNode;
        return;
    }
    Node* ptr = head;
    while(ptr && ptr->data != targetValue) ptr = ptr->next;
    if(!ptr){
        cout<<"Target value wasn't found"<<endl;
        delete newNode;
        return;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}
void deleteBegin(){
    if(!head) return;
    Node* ptr = head;
    head = head->next;
    delete ptr;
}
void deleteEnd(){
    if(!head) return;
    if(!head->next){
        delete head;
        head = nullptr;
        return;
    }
    Node* ptr = head;
    Node* ptrPrev = nullptr;
    while(ptr->next){
        ptrPrev = ptr;
        ptr = ptr->next;
    }
    delete ptr;
    ptrPrev->next = nullptr;
}
void deleteAtPosition(int targetValue){
    if(!head) return;
    if(head->data == targetValue){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* ptr = head;
    Node* ptrPrev = nullptr;
    while(ptr && ptr->data != targetValue){
        ptrPrev = ptr;
        ptr = ptr->next;
    }
    if(!ptr){
        cout<<"Target value wasn't found"<<endl;
        return;
    }
    ptrPrev->next = ptr->next;
    delete ptr;
}
int sumOfElements(Node* head){
    int sum = 0;
    Node* ptr = head;
    while(ptr){
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}
Node* reverseList(Node* head){
    Node* newHead = nullptr;
    Node* ptr = head;
    Node* ptrPrev = nullptr;
    while(ptr){
        ptrPrev = ptr;
        ptr = ptr->next;
        ptrPrev->next = newHead;
        newHead = ptrPrev;
    }
    return newHead;
}
bool isSorted(Node* head){
    Node* ptr = head;
    Node* ptrPrev = nullptr;
    while(ptr->next){
        ptrPrev = ptr;
        ptr = ptr->next;
        if(ptrPrev->data < ptr->data) return false;
    }
    return true;
}