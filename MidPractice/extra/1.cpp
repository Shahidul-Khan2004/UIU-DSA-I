#include <iostream>
#include <vector>

using namespace std;

// Binary Search function that works for both ascending and descending order
// Returns the index of target if found, otherwise returns -1
int binarySearch(vector<int> &arr, int target) {
    int start = 0; int end = arr.size() - 1; bool isAsc = (arr[0] < arr[1]) ? true : false;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(isAsc) {
            if (arr[mid] == target) return mid;
            else if (arr[mid] > target) end = mid - 1;
            else start = mid + 1;
        } else {
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) end = mid - 1;
            else start = mid + 1;
        }
    }
    return -1;
}

void printArray(const vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test Case 1: Ascending order array
    cout << "Test Case 1: Ascending Order Array" << endl;
    vector<int> ascArr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    cout << "Array: ";
    printArray(ascArr);
    
    cout << "Searching for 23: Index = " << binarySearch(ascArr, 23) << " (Expected: 5)" << endl;
    cout << "Searching for 2: Index = " << binarySearch(ascArr, 2) << " (Expected: 0)" << endl;
    cout << "Searching for 78: Index = " << binarySearch(ascArr, 78) << " (Expected: 10)" << endl;
    cout << "Searching for 50: Index = " << binarySearch(ascArr, 50) << " (Expected: -1)" << endl;
    cout << "Searching for 1: Index = " << binarySearch(ascArr, 1) << " (Expected: -1)" << endl;
    cout << "Searching for 100: Index = " << binarySearch(ascArr, 100) << " (Expected: -1)" << endl;
    cout << endl;

    // Test Case 2: Descending order array
    cout << "Test Case 2: Descending Order Array" << endl;
    vector<int> descArr = {90, 75, 60, 50, 40, 30, 20, 10, 5, 1};
    cout << "Array: ";
    printArray(descArr);
    
    cout << "Searching for 30: Index = " << binarySearch(descArr, 30) << " (Expected: 5)" << endl;
    cout << "Searching for 90: Index = " << binarySearch(descArr, 90) << " (Expected: 0)" << endl;
    cout << "Searching for 1: Index = " << binarySearch(descArr, 1) << " (Expected: 9)" << endl;
    cout << "Searching for 45: Index = " << binarySearch(descArr, 45) << " (Expected: -1)" << endl;
    cout << "Searching for 0: Index = " << binarySearch(descArr, 0) << " (Expected: -1)" << endl;
    cout << "Searching for 100: Index = " << binarySearch(descArr, 100) << " (Expected: -1)" << endl;
    cout << endl;

    // Test Case 3: Single element array (ascending)
    cout << "Test Case 3: Single Element Array" << endl;
    vector<int> singleArr = {42};
    cout << "Array: ";
    printArray(singleArr);
    
    cout << "Searching for 42: Index = " << binarySearch(singleArr, 42) << " (Expected: 0)" << endl;
    cout << "Searching for 10: Index = " << binarySearch(singleArr, 10) << " (Expected: -1)" << endl;
    cout << endl;

    // Test Case 4: Two elements array (ascending)
    cout << "Test Case 4: Two Elements Array (Ascending)" << endl;
    vector<int> twoAsc = {10, 20};
    cout << "Array: ";
    printArray(twoAsc);
    
    cout << "Searching for 10: Index = " << binarySearch(twoAsc, 10) << " (Expected: 0)" << endl;
    cout << "Searching for 20: Index = " << binarySearch(twoAsc, 20) << " (Expected: 1)" << endl;
    cout << "Searching for 15: Index = " << binarySearch(twoAsc, 15) << " (Expected: -1)" << endl;
    cout << endl;

    // Test Case 5: Two elements array (descending)
    cout << "Test Case 5: Two Elements Array (Descending)" << endl;
    vector<int> twoDesc = {20, 10};
    cout << "Array: ";
    printArray(twoDesc);
    
    cout << "Searching for 20: Index = " << binarySearch(twoDesc, 20) << " (Expected: 0)" << endl;
    cout << "Searching for 10: Index = " << binarySearch(twoDesc, 10) << " (Expected: 1)" << endl;
    cout << "Searching for 15: Index = " << binarySearch(twoDesc, 15) << " (Expected: -1)" << endl;
    cout << endl;

    // Test Case 6: Array with duplicate values (ascending)
    cout << "Test Case 6: Array with Duplicates (Ascending)" << endl;
    vector<int> dupAsc = {1, 3, 5, 5, 5, 7, 9};
    cout << "Array: ";
    printArray(dupAsc);
    
    cout << "Searching for 5: Index = " << binarySearch(dupAsc, 5) << " (Expected: 2, 3, or 4)" << endl;
    cout << "Searching for 1: Index = " << binarySearch(dupAsc, 1) << " (Expected: 0)" << endl;
    cout << "Searching for 9: Index = " << binarySearch(dupAsc, 9) << " (Expected: 6)" << endl;
    cout << endl;

    // Test Case 7: Array with negative numbers (ascending)
    cout << "Test Case 7: Array with Negative Numbers (Ascending)" << endl;
    vector<int> negAsc = {-50, -30, -10, 0, 10, 30, 50};
    cout << "Array: ";
    printArray(negAsc);
    
    cout << "Searching for -10: Index = " << binarySearch(negAsc, -10) << " (Expected: 2)" << endl;
    cout << "Searching for 0: Index = " << binarySearch(negAsc, 0) << " (Expected: 3)" << endl;
    cout << "Searching for 50: Index = " << binarySearch(negAsc, 50) << " (Expected: 6)" << endl;
    cout << "Searching for -100: Index = " << binarySearch(negAsc, -100) << " (Expected: -1)" << endl;
    cout << endl;

    // Test Case 8: Array with negative numbers (descending)
    cout << "Test Case 8: Array with Negative Numbers (Descending)" << endl;
    vector<int> negDesc = {50, 30, 10, 0, -10, -30, -50};
    cout << "Array: ";
    printArray(negDesc);
    
    cout << "Searching for -10: Index = " << binarySearch(negDesc, -10) << " (Expected: 4)" << endl;
    cout << "Searching for 0: Index = " << binarySearch(negDesc, 0) << " (Expected: 3)" << endl;
    cout << "Searching for 50: Index = " << binarySearch(negDesc, 50) << " (Expected: 0)" << endl;
    cout << "Searching for 100: Index = " << binarySearch(negDesc, 100) << " (Expected: -1)" << endl;

    return 0;
}
