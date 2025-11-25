#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int element);


int main() {
    vector<int> arr;
    int n, x;

    // Take size of array
    cout << "Enter size: ";
    cin >> n;

    // Take array elements
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    // Take the element to search
    cout << "Enter the element: ";
    cin >> x;

    // Search
    int index = binarySearch(arr, x);
    cout << "Should be inserted at index " << index << endl;
}

int binarySearch(vector<int> &arr, int element) {
    int i = 0, j = arr.size();
    while(i <= j) {
        int index = (i + j) / 2;
        if(arr[index] == element) return index + 1;
        else if (arr[index] > element) j = index - 1;
        else i = index + 1;
    }
    return i;
}