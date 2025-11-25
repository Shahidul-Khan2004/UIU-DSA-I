#include <iostream>
#include <vector>

using namespace std;

vector<int> linearSearch(vector<int> &arr, int element);


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

    // Array for occurances
    vector<int> occ;

    // Search
    occ = linearSearch(arr, x);
    if(occ.empty()) cout << "Err: -1 -> Element not found." << endl;
    else cout << "Element found at index ";
    for(int i = 0; i < occ.size(); i++) cout << occ[i] << " ";
    cout << "of the sorted array" << endl;
}

vector<int> linearSearch(vector<int> &arr, int element) {
    vector<int> occ;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == element) occ.push_back(i);
    }
    return occ;
}