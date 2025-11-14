#include <iostream>
#include <vector>
#include <string>

using namespace std;

void swap (string &a, string &b);
void sort (vector<string> &v);

int main () {
    int n;
    cout << "enter the size: ";
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        v.push_back(x);
    }
    sort(v);
    for (int i = 0; i < n; i++) {
        cout << v.at(i) << ' ';
    }
    cout << endl;
}

void swap (string &a, string &b) {
    const string temp = a;
    a = b;
    b = temp;
}

void sort (vector<string> &v) {
    for (int i = v.size() - 1; i > 0; i--) {
        string max = v.front();
        int max_i = 0;
        for (int j = 0; j <= i; j++) {
            if((v.at(j)).length() > (max).length()) {
                max = v.at(j);
                max_i = j;
            }
        }
        swap(v.at(max_i), v.at(i));
    }
}