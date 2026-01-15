#include <iostream>
#include <vector>

using namespace std;

vector<int> binarySearch(vector<int> &arr, int element);


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
    vector<int> occ = binarySearch(arr, x);
    if(occ.empty()) cout << "Err: -1 -> Element not found." << endl;
    else {
        cout << "Element found at index ";
        for(int i = 0; i < occ.size(); i++) cout << occ[i] << " ";
    }
}

vector<int> binarySearch(vector<int> &arr, int element) {
    int i = 0, j = arr.size(); 
    vector<int> occ;
    while(i <= j) {
        int index = (i + j) / 2;
        if(arr[index] == element) occ.push_back(index);
        else if (arr[index] > element) j = index - 1;
        else i = index + 1;
    }
    return occ;
}