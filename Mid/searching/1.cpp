#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> &arr, int element);


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
    int index = linearSearch(arr, x);
    if(index < 0) cout << "Err: " << index << " -> Element not found." << endl;
    else cout << "Element found at index " << index << endl;
}

int linearSearch(vector<int> &arr, int element) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == element) return i;
    }
    return -1;
}