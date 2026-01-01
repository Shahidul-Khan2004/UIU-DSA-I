#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr);
void selectionSort(vector<int> &arr);
void bubbleSort(vector<int> &arr);
void printArr(vector<int> &arr);

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    bubbleSort(arr);
    printArr(arr);

    arr = {5, 4, 3, 2, 1};
    selectionSort(arr);
    printArr(arr);

    arr = {5, 4, 3, 2, 1};
    insertionSort(arr);
    printArr(arr);
}

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for(int i = n-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
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

void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for(int i = n-1; i > 0; i--) {
        int max = arr[0];
        int max_i = 0;
        for(int j = 0; j <= i; j++) {
            if(arr[j] > max) {
                max = arr[j];
                max_i = j;
            }
        }
        swap(arr[max_i], arr[i]);
    }
}

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}