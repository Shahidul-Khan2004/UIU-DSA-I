#include <iostream>
#include <vector>

using namespace std;

void swap (int &a, int &b);
void sort (vector<int> &v);

int main () {
    int n1; int n2;
    cout << "enter the size(array a): ";
    cin >> n1;
    cout << "enter the size(array b): ";
    cin >> n2;
    vector<int> v;
    cout << "enter array a: ";
    for (int i = 0; i < n1; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    cout << "enter array b: ";
    for (int i = 0; i < n2; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << ' ';
    }
    cout << endl;
}

void swap (int &a, int &b) {
    const int temp = a;
    a = b;
    b = temp;
}

void sort (vector<int> &v) {
    for (int i = v.size() - 1; i > 0; i--) {
        int max = v.front();
        int max_i = 0;
        for (int j = 0; j <= i; j++) {
            if(v.at(j) > max) {
                max = v.at(j);
                max_i = j;
            }
        }
        swap(v.at(max_i), v.at(i));
    }
}