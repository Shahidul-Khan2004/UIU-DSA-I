#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b);
void selectionSort(vector<int> &arr); 

int main() {
    vector<int> arr;
    int n, k;

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
    cin >> k;

    // Validation
    if(k > n || k < 1) {
        cout << "Err: " << k << " is not a valid index." << endl;
        return 400;
    }

    // Selection Sort
    selectionSort(arr);
    string position;
    if (k == 1) position = "st";
    else if (k == 2) position = "nd";
    else if (k == 3) position = "rd";
    else position = "th";

    cout << "The " << k << position << " smallest element is " << arr[k - 1] << endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int min = arr[i];
        int minIndex = i;
        for(int j = i; j < n; j++){
            if (arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}