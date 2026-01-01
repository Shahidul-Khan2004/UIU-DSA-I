#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int x);

int main() {
    vector<int> asc = {1, 2, 2, 4, 5};
    cout<< binarySearch(asc, 3) << endl;
}

int binarySearch(vector<int> &arr, int x) {
    int start = 0, end = arr.size() - 1, result = arr.size();
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] >= x) {
            result = mid;
            end = mid - 1;
        }
        else start = mid + 1;
    }
    return result;
}