// Problem: https://codeforces.com/problemset/problem/1433/D
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (auto &it : a) cin >> it;
    vector<pair<int, int>> ans;

    int idx = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] != a[0]) {
            idx = i;
            ans.emplace_back(1, i + 1);
        }
    }

    if (idx == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    for (int i = 1; i < n; i++) {
        if (a[i] == a[0]) {
            ans.emplace_back(idx + 1, i + 1);
        }
    }

    for (auto &[p, q] : ans) {
        cout << p << " " << q << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}