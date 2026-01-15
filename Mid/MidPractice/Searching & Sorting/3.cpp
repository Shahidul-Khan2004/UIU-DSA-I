#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int x);

int main() {
    vector<int> asc = {1, 2, 3, 4, 5};
    vector<int> desc = {5, 4, 3, 2, 1};
    cout<< binarySearch(asc, 2) << endl;
    cout<< binarySearch(desc, 2) << endl;
}

// assuming the array will be sorted
int binarySearch(vector<int> &arr, int x) {
    int start = 0, end = arr.size() - 1, mid;
    bool isAsc = arr[start] < arr[end];
    while (start <= end) {
        mid = (start + end) / 2;
        if(isAsc) {
            if (arr[mid] == x) return mid;
            else if (arr[mid] > x) end = mid - 1;
            else start = mid + 1;
        }
        else {
            if (arr[mid] == x) return mid;
            else if (arr[mid] < x) end = mid - 1;
            else start = mid + 1;
        }
    }
    return -1;
}