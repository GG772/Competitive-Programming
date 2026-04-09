#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;

    double val = 0;
    for (int i = 0; i < 4; i++) {
        val *= 10;
        val += (s[i] - '0');
    }

    int tmp = (int) sqrt(val) * (int) sqrt(val);
    if (tmp == val) {
        cout << "0 " << sqrt(val) << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}