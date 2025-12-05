#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* linkedList = NULL;

Node* createNode(int value);
void addStart(Node* node);
void printLinkedList();
void freeLinkedList();

int main(void){
    cout<<"How many nodes do you want?"<<endl;
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        int val; cout<<"Data in node "<<i+1<<": "; cin >> val;
        Node* newNode = createNode(val);
        addStart(newNode);
    }
    printLinkedList();
    freeLinkedList();
}

Node* createNode(int value){
    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void addStart(Node* node){
    if (linkedList != NULL) node->next = linkedList;
    linkedList = node;
}

void printLinkedList(){
    if (linkedList == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* ptr = linkedList;
    while (ptr->next != NULL){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<ptr->data<<endl;
}

void freeLinkedList(){
    Node* ptr = linkedList;
    while(ptr->next != NULL){
        Node* ptrPrev = ptr;
        ptr = ptr->next;
        delete ptrPrev;
    }
    delete ptr;
    linkedList = NULL;
}
