#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b);
void bubbleSort(vector<int> &arr); 
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

    // Bubble Sort
    bubbleSort(arr);

    // Search
    int index = binarySearch(arr, x);
    if(index < 0) cout << "Err: " << index << " -> Element not found." << endl;
    else cout << "Element found at index " << index << " of the sorted array" << endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

int binarySearch(vector<int> &arr, int element) {
    int i = 0, j = arr.size();
    while(i <= j) {
        int index = (i + j) / 2;
        if(arr[index] == element) return index;
        else if (arr[index] > element) j = index - 1;
        else i = index + 1;
    }
    return -1;
}