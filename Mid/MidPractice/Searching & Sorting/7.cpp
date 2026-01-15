#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int x);

int main() {
    vector<int> asc = {1, 2, 3, 4, 15};
    cout<< binarySearch(asc, 13) << endl;
}

int binarySearch(vector<int> &arr, int x) {
    int start = 0, end = arr.size() - 1, result1 = 0, result2 = arr.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] >= x) {
            result2 = mid;
            end = mid - 1;
        }
        else {
            result1 = mid;
            start = mid + 1;
        }
    }
    if (x - arr[result1] > arr[result2] - x) return arr[result2];
    else return arr[result1];
}