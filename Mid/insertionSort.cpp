#include <iostream>
#include <vector>

using namespace std;

void swap (int &a, int &b);
void sort(vector<int> &arr, int n);

int main() {
    int n, k;
    cout << "Size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Elements of the array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void sort(vector<int> &arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] * arr[j] < arr[j - 1] * arr[j - 1]; j--) swap(arr[j], arr[j-1]);
    }
}

void swap (int &a, int &b) {
    const int temp = a;
    a = b;
    b = temp;
}