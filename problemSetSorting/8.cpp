#include <iostream>
#include <vector>

using namespace std;

void swap (int &a, int &b);
void sort (vector<int> &v);
int freq (vector<int> &v, int x);

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
        int min = v.front();
        int min_freq = freq(v, v.front());
        int min_i = 0;
        for (int j = 0; j <= i; j++) {
            if(freq(v, v.at(j)) < min_freq) {
                min = v.at(j);
                min_freq = freq(v, v.at(j));
                min_i = j;
            }
            else if (freq(v, v.at(j)) == min_freq && v.at(j) > min) {
                min = v.at(j);
                min_freq = freq(v, v.at(j));
                min_i = j;
            }
        }
        swap(v.at(min_i), v.at(i));
    }
}

int freq (vector<int> &v, int x) {
    int freq = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i) == x) freq++;
    }
    return freq;
}