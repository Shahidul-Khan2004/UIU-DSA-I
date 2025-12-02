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
    for (int i = n - 1; i > 0; i--) {
        int max = arr[0] * arr[0];
        int max_i = 0;
        for (int j = 0; j <= i; j++) {
            if (arr[j] * arr[j] > max) {
                max = arr[j] * arr[j];
                max_i = j;
            }
        }
        swap(arr[max_i], arr[i]);
    }
}

void swap (int &a, int &b) {
    const int temp = a;
    a = b;
    b = temp;
}