#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr);
void selectionSort(vector<int> &arr);
void bubbleSort(vector<int> &arr);
void printArr(vector<int> &arr);

int main() {
    vector<int> arr = {5, -4, 3, -2, 1};
    bubbleSort(arr);
    printArr(arr);
}

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for(int i = n-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(abs(arr[j]) > abs(arr[j+1])) swap(arr[j], arr[j+1]);
        }
    }
}

void printArr(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[n-1] << endl;
}