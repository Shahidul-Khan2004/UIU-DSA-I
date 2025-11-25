#include <iostream>
#include <vector>

using namespace std;

pair<int, int> linearSearch(vector<int> &arr, int element);


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
    pair<int, int> occ;

    // Search
    occ = linearSearch(arr, x);
    cout << occ.first << ", " << occ.second << endl;
}

pair<int, int> linearSearch(vector<int> &arr, int element) {
    vector<int> occ;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == element) occ.push_back(i);
    }
    if(occ.empty()) return {-1, -1};
    else return {occ[0], occ.back()};
}