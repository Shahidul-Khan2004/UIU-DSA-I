#include <iostream>
#include <vector>

using namespace std;

// Binary Search to find the insertion position of target in ascending sorted array
// Returns the index where target should be inserted to maintain sorted order
int findInsertPosition(vector<int> &arr, int target) {
    int start = 0; int end = arr.size() - 1; int index = arr.size();
    while(start <= end) {
        int mid = (start + end)/2;
        if(arr[mid] > target) {
            index = mid;
            end = mid - 1;
        }
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

void demonstrateInsertion(vector<int> arr, int target) {
    cout << "Original array: ";
    printArray(arr);
    
    int pos = findInsertPosition(arr, target);
    cout << "Insert " << target << " at position: " << pos << endl;
    
    // Actually insert and show result
    arr.insert(arr.begin() + pos, target);
    cout << "After insertion: ";
    printArray(arr);
    cout << endl;
}

int main() {
    // Test Case 1: Insert in the middle
    cout << "Test Case 1: Insert in Middle" << endl;
    vector<int> arr1 = {1, 3, 5, 7, 9};
    demonstrateInsertion(arr1, 6);

    // Test Case 2: Insert at the beginning (smaller than all)
    cout << "Test Case 2: Insert at Beginning" << endl;
    vector<int> arr2 = {5, 10, 15, 20, 25};
    demonstrateInsertion(arr2, 2);

    // Test Case 3: Insert at the end (larger than all)
    cout << "Test Case 3: Insert at End" << endl;
    vector<int> arr3 = {1, 3, 5, 7, 9};
    demonstrateInsertion(arr3, 15);

    // Test Case 4: Insert when element already exists
    cout << "Test Case 4: Element Already Exists" << endl;
    vector<int> arr4 = {1, 3, 5, 7, 9};
    demonstrateInsertion(arr4, 5);

    // Test Case 5: Insert with duplicates present
    cout << "Test Case 5: Array with Duplicates" << endl;
    vector<int> arr5 = {1, 3, 3, 3, 5, 7, 9};
    demonstrateInsertion(arr5, 3);

    // Test Case 6: Single element array - insert before
    cout << "Test Case 6: Single Element - Insert Before" << endl;
    vector<int> arr6 = {10};
    demonstrateInsertion(arr6, 5);

    // Test Case 7: Single element array - insert after
    cout << "Test Case 7: Single Element - Insert After" << endl;
    vector<int> arr7 = {10};
    demonstrateInsertion(arr7, 15);

    // Test Case 8: Single element array - same value
    cout << "Test Case 8: Single Element - Same Value" << endl;
    vector<int> arr8 = {10};
    demonstrateInsertion(arr8, 10);

    // Test Case 9: Two elements
    cout << "Test Case 9: Two Elements" << endl;
    vector<int> arr9 = {10, 20};
    demonstrateInsertion(arr9, 15);

    // Test Case 10: Negative numbers
    cout << "Test Case 10: Negative Numbers" << endl;
    vector<int> arr10 = {-10, -5, 0, 5, 10};
    demonstrateInsertion(arr10, -3);

    // Test Case 11: All negative
    cout << "Test Case 11: All Negative Numbers" << endl;
    vector<int> arr11 = {-50, -30, -10, -5};
    demonstrateInsertion(arr11, -20);

    // Test Case 12: Large gap between elements
    cout << "Test Case 12: Large Gaps" << endl;
    vector<int> arr12 = {1, 100, 200, 300, 400};
    demonstrateInsertion(arr12, 150);

    // Test Case 13: Insert at position 0 with duplicates at start
    cout << "Test Case 13: Duplicates at Start" << endl;
    vector<int> arr13 = {5, 5, 5, 10, 15, 20};
    demonstrateInsertion(arr13, 3);

    // Test Case 14: Insert with duplicates at end
    cout << "Test Case 14: Duplicates at End" << endl;
    vector<int> arr14 = {1, 5, 10, 15, 15, 15};
    demonstrateInsertion(arr14, 20);

    // Test Case 15: All same elements
    cout << "Test Case 15: All Same Elements" << endl;
    vector<int> arr15 = {7, 7, 7, 7, 7};
    demonstrateInsertion(arr15, 7);

    // Additional verification tests
    cout << "\n=== Verification Tests ===" << endl;
    vector<int> test = {1, 3, 5, 7, 9, 11, 13};
    cout << "Test array: ";
    printArray(test);
    cout << "Position for 0: " << findInsertPosition(test, 0) << " (Expected: 0)" << endl;
    cout << "Position for 2: " << findInsertPosition(test, 2) << " (Expected: 1)" << endl;
    cout << "Position for 4: " << findInsertPosition(test, 4) << " (Expected: 2)" << endl;
    cout << "Position for 5: " << findInsertPosition(test, 5) << " (Expected: 2 or 3)" << endl;
    cout << "Position for 10: " << findInsertPosition(test, 10) << " (Expected: 5)" << endl;
    cout << "Position for 13: " << findInsertPosition(test, 13) << " (Expected: 6 or 7)" << endl;
    cout << "Position for 20: " << findInsertPosition(test, 20) << " (Expected: 7)" << endl;

    return 0;
}
