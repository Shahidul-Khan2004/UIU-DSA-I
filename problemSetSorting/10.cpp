#include <iostream>
#include <vector>

using namespace std;

void swap (pair<int,int> &a, pair<int,int> &b);
void sort (vector<pair<int,int>> &v);

int main () {
    int n;
    cout << "enter the size: ";
    cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int y; cin >> y;
        v.emplace_back(x, y);
    }
    sort(v);
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << "(" << v.at(i).first << ", " << v.at(i).second << ")";
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void swap (pair<int,int> &a, pair<int,int> &b) {
    pair<int,int> temp = a;
    a = b;
    b = temp;
}

void sort (vector<pair<int,int>> &v) {
    for (int i = v.size() - 1; i > 0; i--) {
        int max = v.front().second - v.front().first;
        int max_i = 0;
        for (int j = 0; j <= i; j++) {
            int duration = v.at(j).second - v.at(j).first;
            if(duration > max) {
                max = duration;
                max_i = j;
            }
        }
        swap(v.at(max_i), v.at(i));
    }
}