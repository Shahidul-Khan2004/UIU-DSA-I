#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Binary Search to find the closest element to target in ascending sorted array
// If two elements are equally close, return the smaller one
// Returns the closest element value
int findClosestElement(vector<int> &arr, int target) {
    int start = 0; int end = arr.size() - 1;
    int minIndex = 0; int maxIndex = arr.size()-1;
    while (start <= end) {
        int mid = (start + end)/2;
        if(arr[mid] > target) {
            maxIndex = mid;
            end = mid - 1;
        }
        else {
            minIndex = mid;
            start = start + 1;
        }
    }
    return (arr[maxIndex] - target > target - arr[minIndex]) ? arr[minIndex] : arr[maxIndex];
}

void printArray(const vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test Case 1: Target exists in array
    cout << "Test Case 1: Target Exists in Array" << endl;
    vector<int> arr1 = {1, 3, 5, 7, 9, 11, 13};
    cout << "Array: ";
    printArray(arr1);
    cout << "Closest to 7: " << findClosestElement(arr1, 7) << " (Expected: 7)" << endl;
    cout << "Closest to 1: " << findClosestElement(arr1, 1) << " (Expected: 1)" << endl;
    cout << "Closest to 13: " << findClosestElement(arr1, 13) << " (Expected: 13)" << endl;
    cout << endl;

    // Test Case 2: Target between two elements (closer to left)
    cout << "Test Case 2: Target Closer to Left Element" << endl;
    vector<int> arr2 = {10, 20, 30, 40, 50};
    cout << "Array: ";
    printArray(arr2);
    cout << "Closest to 22: " << findClosestElement(arr2, 22) << " (Expected: 20)" << endl;
    cout << "Closest to 12: " << findClosestElement(arr2, 12) << " (Expected: 10)" << endl;
    cout << endl;

    // Test Case 3: Target between two elements (closer to right)
    cout << "Test Case 3: Target Closer to Right Element" << endl;
    vector<int> arr3 = {10, 20, 30, 40, 50};
    cout << "Array: ";
    printArray(arr3);
    cout << "Closest to 28: " << findClosestElement(arr3, 28) << " (Expected: 30)" << endl;
    cout << "Closest to 48: " << findClosestElement(arr3, 48) << " (Expected: 50)" << endl;
    cout << endl;

    // Test Case 4: Equally close - return smaller
    cout << "Test Case 4: Equally Close - Return Smaller" << endl;
    vector<int> arr4 = {10, 20, 30, 40, 50};
    cout << "Array: ";
    printArray(arr4);
    cout << "Closest to 15: " << findClosestElement(arr4, 15) << " (Expected: 10, distance 5 each)" << endl;
    cout << "Closest to 25: " << findClosestElement(arr4, 25) << " (Expected: 20, distance 5 each)" << endl;
    cout << "Closest to 35: " << findClosestElement(arr4, 35) << " (Expected: 30, distance 5 each)" << endl;
    cout << "Closest to 45: " << findClosestElement(arr4, 45) << " (Expected: 40, distance 5 each)" << endl;
    cout << endl;

    // Test Case 5: Target smaller than all elements
    cout << "Test Case 5: Target Smaller Than All" << endl;
    vector<int> arr5 = {10, 20, 30, 40, 50};
    cout << "Array: ";
    printArray(arr5);
    cout << "Closest to 5: " << findClosestElement(arr5, 5) << " (Expected: 10)" << endl;
    cout << "Closest to 0: " << findClosestElement(arr5, 0) << " (Expected: 10)" << endl;
    cout << "Closest to -100: " << findClosestElement(arr5, -100) << " (Expected: 10)" << endl;
    cout << endl;

    // Test Case 6: Target larger than all elements
    cout << "Test Case 6: Target Larger Than All" << endl;
    vector<int> arr6 = {10, 20, 30, 40, 50};
    cout << "Array: ";
    printArray(arr6);
    cout << "Closest to 55: " << findClosestElement(arr6, 55) << " (Expected: 50)" << endl;
    cout << "Closest to 100: " << findClosestElement(arr6, 100) << " (Expected: 50)" << endl;
    cout << "Closest to 1000: " << findClosestElement(arr6, 1000) << " (Expected: 50)" << endl;
    cout << endl;

    // Test Case 7: Single element
    cout << "Test Case 7: Single Element Array" << endl;
    vector<int> arr7 = {42};
    cout << "Array: ";
    printArray(arr7);
    cout << "Closest to 42: " << findClosestElement(arr7, 42) << " (Expected: 42)" << endl;
    cout << "Closest to 10: " << findClosestElement(arr7, 10) << " (Expected: 42)" << endl;
    cout << "Closest to 100: " << findClosestElement(arr7, 100) << " (Expected: 42)" << endl;
    cout << endl;

    // Test Case 8: Two elements
    cout << "Test Case 8: Two Elements" << endl;
    vector<int> arr8 = {10, 30};
    cout << "Array: ";
    printArray(arr8);
    cout << "Closest to 15: " << findClosestElement(arr8, 15) << " (Expected: 10)" << endl;
    cout << "Closest to 25: " << findClosestElement(arr8, 25) << " (Expected: 30)" << endl;
    cout << "Closest to 20: " << findClosestElement(arr8, 20) << " (Expected: 10, equal distance)" << endl;
    cout << "Closest to 5: " << findClosestElement(arr8, 5) << " (Expected: 10)" << endl;
    cout << "Closest to 35: " << findClosestElement(arr8, 35) << " (Expected: 30)" << endl;
    cout << endl;

    // Test Case 9: Negative numbers
    cout << "Test Case 9: Array with Negative Numbers" << endl;
    vector<int> arr9 = {-50, -30, -10, 0, 10, 30, 50};
    cout << "Array: ";
    printArray(arr9);
    cout << "Closest to -20: " << findClosestElement(arr9, -20) << " (Expected: -10 or -30, should return -30)" << endl;
    cout << "Closest to -5: " << findClosestElement(arr9, -5) << " (Expected: -10)" << endl;
    cout << "Closest to 5: " << findClosestElement(arr9, 5) << " (Expected: 0)" << endl;
    cout << "Closest to 20: " << findClosestElement(arr9, 20) << " (Expected: 10 or 30, should return 10)" << endl;
    cout << "Closest to -60: " << findClosestElement(arr9, -60) << " (Expected: -50)" << endl;
    cout << "Closest to 60: " << findClosestElement(arr9, 60) << " (Expected: 50)" << endl;
    cout << endl;

    // Test Case 10: All negative numbers
    cout << "Test Case 10: All Negative Numbers" << endl;
    vector<int> arr10 = {-100, -80, -60, -40, -20};
    cout << "Array: ";
    printArray(arr10);
    cout << "Closest to -70: " << findClosestElement(arr10, -70) << " (Expected: -60 or -80, should return -80)" << endl;
    cout << "Closest to -50: " << findClosestElement(arr10, -50) << " (Expected: -40 or -60, should return -60)" << endl;
    cout << "Closest to -30: " << findClosestElement(arr10, -30) << " (Expected: -20 or -40, should return -40)" << endl;
    cout << endl;

    // Test Case 11: Array with duplicates
    cout << "Test Case 11: Array with Duplicates" << endl;
    vector<int> arr11 = {1, 5, 5, 5, 10, 15, 20};
    cout << "Array: ";
    printArray(arr11);
    cout << "Closest to 5: " << findClosestElement(arr11, 5) << " (Expected: 5)" << endl;
    cout << "Closest to 7: " << findClosestElement(arr11, 7) << " (Expected: 5)" << endl;
    cout << "Closest to 8: " << findClosestElement(arr11, 8) << " (Expected: 10)" << endl;
    cout << endl;

    // Test Case 12: Large gaps
    cout << "Test Case 12: Large Gaps Between Elements" << endl;
    vector<int> arr12 = {1, 100, 200, 1000};
    cout << "Array: ";
    printArray(arr12);
    cout << "Closest to 50: " << findClosestElement(arr12, 50) << " (Expected: 1 or 100, should return 1)" << endl;
    cout << "Closest to 51: " << findClosestElement(arr12, 51) << " (Expected: 100)" << endl;
    cout << "Closest to 150: " << findClosestElement(arr12, 150) << " (Expected: 100 or 200, should return 100)" << endl;
    cout << "Closest to 600: " << findClosestElement(arr12, 600) << " (Expected: 200 or 1000, should return 200)" << endl;
    cout << endl;

    // Test Case 13: Consecutive numbers
    cout << "Test Case 13: Consecutive Numbers" << endl;
    vector<int> arr13 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Array: ";
    printArray(arr13);
    cout << "Closest to 4: " << findClosestElement(arr13, 4) << " (Expected: 4)" << endl;
    cout << "Closest to 0: " << findClosestElement(arr13, 0) << " (Expected: 1)" << endl;
    cout << "Closest to 11: " << findClosestElement(arr13, 11) << " (Expected: 10)" << endl;
    cout << endl;

    // Test Case 14: Edge case with zero
    cout << "Test Case 14: Edge Case with Zero" << endl;
    vector<int> arr14 = {-5, 0, 5};
    cout << "Array: ";
    printArray(arr14);
    cout << "Closest to 0: " << findClosestElement(arr14, 0) << " (Expected: 0)" << endl;
    cout << "Closest to -2: " << findClosestElement(arr14, -2) << " (Expected: 0)" << endl;
    cout << "Closest to 2: " << findClosestElement(arr14, 2) << " (Expected: 0)" << endl;
    cout << "Closest to -3: " << findClosestElement(arr14, -3) << " (Expected: -5)" << endl;
    cout << "Closest to 3: " << findClosestElement(arr14, 3) << " (Expected: 5)" << endl;

    return 0;
}
