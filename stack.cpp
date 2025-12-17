#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    char c;
    Node* next;
};

struct Node* top;

void llpush(char c) {
    Node* temp = new Node();
    temp -> c = c;
    temp -> next = top;
    top = temp;
}

char lltop(){ return top -> c;}

void llpop(){
    if(!top) return;
    Node* ptr= top;
    top = top -> next;
    delete ptr;
}

char arr[10];
int atop = -1;

void apush(char c){
    if(atop == 9){
        cout << "stack full" << endl;
        return;
    }
    atop++;
    arr[atop] = c;
}

char aatop() {
    return arr[atop];
}

void apop() { atop--; }

int main(){
    //with in-built stack
    stack<char> word;
    word.push('N'); word.push('e'); word.push('p'); word.push('a'); word.push('l');
    string reverse = "";
    for(int i = 0; i < 5; i++) {
        reverse += word.top();
        word.pop();
    }
    cout << reverse << endl;

    //stack with linked list
    llpush('N'); llpush('e'); llpush('p'); llpush('a'); llpush('l');
    string llreverse = "";
    for(int i = 0; i < 5; i++) {
        llreverse += lltop();
        llpop();
    }
    cout << llreverse << endl;

    //stack with array
    apush('N'); apush('e'); apush('p'); apush('a'); apush('l');
    string areverse = "";
    for(int i = 0; i < 5; i++) {
        areverse += aatop();
        apop();
    }
    cout << areverse << endl;
}