#include <iostream>
#include <vector>

using namespace std;

// Binary Search to find the first occurrence of target in ascending sorted array
// Returns the index of first occurrence if found, otherwise returns -1
int findFirstOccurrence(vector<int> &arr, int target) {
    int start = 0; int end = arr.size() - 1; int index = -1;
    while (start <= end) {
        int mid = (start + end)/2;
        if(arr[mid] == target) {
            index = mid;
            end = mid - 1;
        }
        else if (arr[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return index;
}

void printArray(const vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test Case 1: Array with multiple occurrences in the middle
    cout << "Test Case 1: Multiple Occurrences in Middle" << endl;
    vector<int> arr1 = {1, 2, 3, 5, 5, 5, 5, 5, 7, 8, 9};
    cout << "Array: ";
    printArray(arr1);
    
    cout << "Searching for 5: Index = " << findFirstOccurrence(arr1, 5) << " (Expected: 3)" << endl;
    cout << "Searching for 1: Index = " << findFirstOccurrence(arr1, 1) << " (Expected: 0)" << endl;
    cout << "Searching for 9: Index = " << findFirstOccurrence(arr1, 9) << " (Expected: 10)" << endl;
    cout << "Searching for 4: Index = " << findFirstOccurrence(arr1, 4) << " (Expected: -1)" << endl;
    cout << endl;

    // Test Case 2: All elements are the same
    cout << "Test Case 2: All Elements Same" << endl;
    vector<int> arr2 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Array: ";
    printArray(arr2);
    
    cout << "Searching for 7: Index = " << findFirstOccurrence(arr2, 7) << " (Expected: 0)" << endl;
    cout << "Searching for 5: Index = " << findFirstOccurrence(arr2, 5) << " (Expected: -1)" << endl;
    cout << endl;

    // Test Case 3: Duplicates at the beginning
    cout << "Test Case 3: Duplicates at Beginning" << endl;
    vector<int> arr3 = {2, 2, 2, 2, 5, 8, 10, 15};
    cout << "Array: ";
    printArray(arr3);
    
    cout << "Searching for 2: Index = " << findFirstOccurrence(arr3, 2) << " (Expected: 0)" << endl;
    cout << "Searching for 5: Index = " << findFirstOccurrence(arr3, 5) << " (Expected: 4)" << endl;
    cout << "Searching for 15: Index = " << findFirstOccurrence(arr3, 15) << " (Expected: 7)" << endl;
    cout << endl;

    // Test Case 4: Duplicates at the end
    cout << "Test Case 4: Duplicates at End" << endl;
    vector<int> arr4 = {1, 3, 5, 7, 9, 9, 9, 9};
    cout << "Array: ";
    printArray(arr4);
    
    cout << "Searching for 9: Index = " << findFirstOccurrence(arr4, 9) << " (Expected: 4)" << endl;
    cout << "Searching for 1: Index = " << findFirstOccurrence(arr4, 1) << " (Expected: 0)" << endl;
    cout << "Searching for 3: Index = " << findFirstOccurrence(arr4, 3) << " (Expected: 1)" << endl;
    cout << endl;

    // Test Case 5: Two consecutive duplicates
    cout << "Test Case 5: Pairs of Duplicates" << endl;
    vector<int> arr5 = {1, 1, 3, 3, 5, 5, 7, 7, 9, 9};
    cout << "Array: ";
    printArray(arr5);
    
    cout << "Searching for 1: Index = " << findFirstOccurrence(arr5, 1) << " (Expected: 0)" << endl;
    cout << "Searching for 3: Index = " << findFirstOccurrence(arr5, 3) << " (Expected: 2)" << endl;
    cout << "Searching for 5: Index = " << findFirstOccurrence(arr5, 5) << " (Expected: 4)" << endl;
    cout << "Searching for 7: Index = " << findFirstOccurrence(arr5, 7) << " (Expected: 6)" << endl;
    cout << "Searching for 9: Index = " << findFirstOccurrence(arr5, 9) << " (Expected: 8)" << endl;
    cout << endl;

    // Test Case 6: No duplicates (unique elements)
    cout << "Test Case 6: No Duplicates" << endl;
    vector<int> arr6 = {2, 5, 8, 12, 16, 23, 38, 45};
    cout << "Array: ";
    printArray(arr6);
    
    cout << "Searching for 23: Index = " << findFirstOccurrence(arr6, 23) << " (Expected: 5)" << endl;
    cout << "Searching for 2: Index = " << findFirstOccurrence(arr6, 2) << " (Expected: 0)" << endl;
    cout << "Searching for 45: Index = " << findFirstOccurrence(arr6, 45) << " (Expected: 7)" << endl;
    cout << "Searching for 20: Index = " << findFirstOccurrence(arr6, 20) << " (Expected: -1)" << endl;
    cout << endl;

    // Test Case 7: Single element
    cout << "Test Case 7: Single Element" << endl;
    vector<int> arr7 = {42};
    cout << "Array: ";
    printArray(arr7);
    
    cout << "Searching for 42: Index = " << findFirstOccurrence(arr7, 42) << " (Expected: 0)" << endl;
    cout << "Searching for 10: Index = " << findFirstOccurrence(arr7, 10) << " (Expected: -1)" << endl;
    cout << endl;

    // Test Case 8: Two elements (both same)
    cout << "Test Case 8: Two Same Elements" << endl;
    vector<int> arr8 = {10, 10};
    cout << "Array: ";
    printArray(arr8);
    
    cout << "Searching for 10: Index = " << findFirstOccurrence(arr8, 10) << " (Expected: 0)" << endl;
    cout << "Searching for 5: Index = " << findFirstOccurrence(arr8, 5) << " (Expected: -1)" << endl;
    cout << endl;

    // Test Case 9: Large number of duplicates
    cout << "Test Case 9: Many Duplicates" << endl;
    vector<int> arr9 = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5};
    cout << "Array: ";
    printArray(arr9);
    
    cout << "Searching for 3: Index = " << findFirstOccurrence(arr9, 3) << " (Expected: 2)" << endl;
    cout << "Searching for 1: Index = " << findFirstOccurrence(arr9, 1) << " (Expected: 0)" << endl;
    cout << "Searching for 5: Index = " << findFirstOccurrence(arr9, 5) << " (Expected: 13)" << endl;
    cout << endl;

    // Test Case 10: Negative numbers with duplicates
    cout << "Test Case 10: Negative Numbers with Duplicates" << endl;
    vector<int> arr10 = {-10, -10, -5, -5, -5, 0, 0, 5, 10};
    cout << "Array: ";
    printArray(arr10);
    
    cout << "Searching for -10: Index = " << findFirstOccurrence(arr10, -10) << " (Expected: 0)" << endl;
    cout << "Searching for -5: Index = " << findFirstOccurrence(arr10, -5) << " (Expected: 2)" << endl;
    cout << "Searching for 0: Index = " << findFirstOccurrence(arr10, 0) << " (Expected: 5)" << endl;
    cout << "Searching for 5: Index = " << findFirstOccurrence(arr10, 5) << " (Expected: 7)" << endl;
    cout << "Searching for -20: Index = " << findFirstOccurrence(arr10, -20) << " (Expected: -1)" << endl;

    return 0;
}
