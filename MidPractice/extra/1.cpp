#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(const vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test Case 1: Normal unsorted array
    cout << "Test Case 1: Normal unsorted array" << endl;
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    cout << "Before: ";
    printArray(arr1);
    insertionSort(arr1);
    cout << "After:  ";
    printArray(arr1);
    cout << endl;

    // Test Case 2: Already sorted array
    cout << "Test Case 2: Already sorted array" << endl;
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Before: ";
    printArray(arr2);
    insertionSort(arr2);
    cout << "After:  ";
    printArray(arr2);
    cout << endl;

    // Test Case 3: Reverse sorted array (worst case)
    cout << "Test Case 3: Reverse sorted array" << endl;
    vector<int> arr3 = {5, 4, 3, 2, 1};
    cout << "Before: ";
    printArray(arr3);
    insertionSort(arr3);
    cout << "After:  ";
    printArray(arr3);
    cout << endl;

    // Test Case 4: Array with duplicates
    cout << "Test Case 4: Array with duplicates" << endl;
    vector<int> arr4 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    cout << "Before: ";
    printArray(arr4);
    insertionSort(arr4);
    cout << "After:  ";
    printArray(arr4);
    cout << endl;

    // Test Case 5: Single element
    cout << "Test Case 5: Single element" << endl;
    vector<int> arr5 = {42};
    cout << "Before: ";
    printArray(arr5);
    insertionSort(arr5);
    cout << "After:  ";
    printArray(arr5);
    cout << endl;

    // Test Case 6: Two elements
    cout << "Test Case 6: Two elements" << endl;
    vector<int> arr6 = {2, 1};
    cout << "Before: ";
    printArray(arr6);
    insertionSort(arr6);
    cout << "After:  ";
    printArray(arr6);
    cout << endl;

    // Test Case 7: Empty array
    cout << "Test Case 7: Empty array" << endl;
    vector<int> arr7 = {};
    cout << "Before: ";
    printArray(arr7);
    insertionSort(arr7);
    cout << "After:  ";
    printArray(arr7);
    cout << endl;

    // Test Case 8: Array with negative numbers
    cout << "Test Case 8: Array with negative numbers" << endl;
    vector<int> arr8 = {-5, 2, -8, 12, -3, 0, 7};
    cout << "Before: ";
    printArray(arr8);
    insertionSort(arr8);
    cout << "After:  ";
    printArray(arr8);
    
    return 0;
}