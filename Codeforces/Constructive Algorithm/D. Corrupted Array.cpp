// Problem: https://codeforces.com/problemset/problem/1512/D

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> b(n+2);

    ll s = 0;

    for (int i = 0; i < n + 2; i++) {
        cin >> b[i];
        s += b[i];
    }

    sort(b.begin(), b.end());
    int idx = -1;
    for (int i = 0; i < n + 1; i++) {
        if (s - b[n + 1] - b[i] == b[n+1]) {
            idx = i;
            break;
        }
    }

    if (idx != -1) {
        for (int i = 0; i < n + 1; i++) {
            if (i != idx) cout << b[i] << " ";
        }
        cout << "\n";
        return;
    } else if (s - b[n+1] - b[n] == b[n]) {
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        return;
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