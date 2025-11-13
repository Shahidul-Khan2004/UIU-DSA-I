#include <iostream>
#include <vector>

using namespace std;

void swap (int &a, int &b);
void sort(vector<int> &arr, int n);

int main() {
    int n;
    cout << "Size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Elements of the array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, n);
    if (n % 2 == 0) cout << (arr[n/2] + arr[n/2 - 1]) / 2.0 << endl;
    else cout << arr[n/2] << endl;
}

void sort(vector<int> &arr, int n) {
    for (int i = n - 1; i >= 0; i--) {
        int max = arr[0];
        int max_i = 0;
        for (int j = 0; j <= i; j++) {
            if (arr[j] > max) {
                max = arr[j];
                max_i = j;
            }
        }
        swap(arr[i], arr[max_i]);
    }
}

void swap (int &a, int &b) {
    const int temp = a;
    a = b;
    b = temp;
}