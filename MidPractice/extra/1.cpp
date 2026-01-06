#include <iostream>

using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a new node with value x into sorted linked list
// Returns the head of the modified list
Node* insertSorted(Node* head, int x) {
    
    Node* tmp = new Node(x);

    if (!head || head->data >= x) {
        tmp->next = head;
        head = tmp;
        return head;
    }

    Node* ptr = head;
    while(ptr->next && ptr->next->data < x) ptr = ptr->next;
    tmp->next = ptr->next;
    ptr->next = tmp;
    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data;
        if(temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
Node* createList(int arr[], int size) {
    if(size == 0) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* temp = head;
    
    for(int i = 1; i < size; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    
    return head;
}

// Helper function to free the linked list memory
void deleteList(Node* head) {
    while(head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Helper function to count nodes in the list
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void testInsertion(int arr[], int size, int value) {
    Node* head = createList(arr, size);
    
    cout << "Original List: ";
    if(head == nullptr) cout << "Empty";
    else printList(head);
    
    cout << "Insert value: " << value << endl;
    
    head = insertSorted(head, value);
    
    cout << "After Insertion: ";
    printList(head);
    cout << "Total nodes: " << countNodes(head) << endl;
    cout << endl;
    
    deleteList(head);
}

int main() {
    // Test Case 1: Insert in the middle
    cout << "Test Case 1: Insert in Middle" << endl;
    int arr1[] = {1, 3, 5, 7, 9};
    testInsertion(arr1, 5, 6);

    // Test Case 2: Insert at the beginning
    cout << "Test Case 2: Insert at Beginning" << endl;
    int arr2[] = {5, 10, 15, 20, 25};
    testInsertion(arr2, 5, 2);

    // Test Case 3: Insert at the end
    cout << "Test Case 3: Insert at End" << endl;
    int arr3[] = {1, 3, 5, 7, 9};
    testInsertion(arr3, 5, 15);

    // Test Case 4: Insert duplicate value
    cout << "Test Case 4: Insert Duplicate Value" << endl;
    int arr4[] = {1, 3, 5, 7, 9};
    testInsertion(arr4, 5, 5);

    // Test Case 5: Insert into empty list
    cout << "Test Case 5: Insert into Empty List" << endl;
    int arr5[] = {};
    testInsertion(arr5, 0, 10);

    // Test Case 6: Insert into single element list (smaller)
    cout << "Test Case 6: Single Element List - Insert Smaller" << endl;
    int arr6[] = {10};
    testInsertion(arr6, 1, 5);

    // Test Case 7: Insert into single element list (larger)
    cout << "Test Case 7: Single Element List - Insert Larger" << endl;
    int arr7[] = {10};
    testInsertion(arr7, 1, 15);

    // Test Case 8: Insert into single element list (equal)
    cout << "Test Case 8: Single Element List - Insert Equal" << endl;
    int arr8[] = {10};
    testInsertion(arr8, 1, 10);

    // Test Case 9: Insert into two element list
    cout << "Test Case 9: Two Element List" << endl;
    int arr9[] = {10, 20};
    testInsertion(arr9, 2, 15);

    // Test Case 10: Insert with negative numbers
    cout << "Test Case 10: Insert with Negative Numbers" << endl;
    int arr10[] = {-10, -5, 0, 5, 10};
    testInsertion(arr10, 5, -3);

    // Test Case 11: All negative numbers
    cout << "Test Case 11: All Negative Numbers" << endl;
    int arr11[] = {-50, -30, -10, -5};
    testInsertion(arr11, 4, -20);

    // Test Case 12: List with duplicates
    cout << "Test Case 12: List with Duplicates" << endl;
    int arr12[] = {1, 3, 3, 3, 5, 7, 9};
    testInsertion(arr12, 7, 3);

    // Test Case 13: Insert at beginning with duplicates
    cout << "Test Case 13: Insert at Beginning with Duplicates" << endl;
    int arr13[] = {5, 5, 5, 10, 15, 20};
    testInsertion(arr13, 6, 3);

    // Test Case 14: Insert at end with duplicates
    cout << "Test Case 14: Insert at End with Duplicates" << endl;
    int arr14[] = {1, 5, 10, 15, 15, 15};
    testInsertion(arr14, 6, 20);

    // Test Case 15: All same elements
    cout << "Test Case 15: All Same Elements" << endl;
    int arr15[] = {7, 7, 7, 7, 7};
    testInsertion(arr15, 5, 7);

    // Test Case 16: Large gap between elements
    cout << "Test Case 16: Large Gaps" << endl;
    int arr16[] = {1, 100, 200, 300, 400};
    testInsertion(arr16, 5, 150);

    // Test Case 17: Consecutive numbers
    cout << "Test Case 17: Consecutive Numbers" << endl;
    int arr17[] = {1, 2, 3, 4, 5};
    testInsertion(arr17, 5, 3);

    // Test Case 18: Insert zero
    cout << "Test Case 18: Insert Zero" << endl;
    int arr18[] = {-5, -3, 2, 5, 10};
    testInsertion(arr18, 5, 0);

    // Test Case 19: Very small value
    cout << "Test Case 19: Very Small Value" << endl;
    int arr19[] = {10, 20, 30, 40, 50};
    testInsertion(arr19, 5, -1000);

    // Test Case 20: Very large value
    cout << "Test Case 20: Very Large Value" << endl;
    int arr20[] = {10, 20, 30, 40, 50};
    testInsertion(arr20, 5, 1000);

    // Multiple insertions test
    cout << "=== Multiple Insertions Test ===" << endl;
    int arr[] = {1, 5, 9};
    Node* head = createList(arr, 3);
    cout << "Initial List: ";
    printList(head);
    
    cout << "\nInserting 3, 7, 0, 10 in sequence..." << endl;
    head = insertSorted(head, 3);
    cout << "After inserting 3: ";
    printList(head);
    
    head = insertSorted(head, 7);
    cout << "After inserting 7: ";
    printList(head);
    
    head = insertSorted(head, 0);
    cout << "After inserting 0: ";
    printList(head);
    
    head = insertSorted(head, 10);
    cout << "After inserting 10: ";
    printList(head);
    
    deleteList(head);

    return 0;
}
