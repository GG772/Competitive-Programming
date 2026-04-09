#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<int> a;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '#') {
            a.push_back(i+1);
        }
    }

    int n = a.size();

    for (int i = 0; i < n; i += 2) {
        cout << a[i] << "," << a[i+1] << endl;
    }
}