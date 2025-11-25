#include <iostream>
#include <vector>

using namespace std;

void swap (int &a, int &b);
void sort (vector<int> &v);

int main () {
    int n;
    cout << "enter the size: ";
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v);
    for (int i = 0; i < n; i++) {
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
            if(abs(v.at(j)) > abs(max)) {
                max = v.at(j);
                max_i = j;
            }
        }
        swap(v.at(max_i), v.at(i));
    }
}