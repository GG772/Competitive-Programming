#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            mp[x]++;
        }
    }

    for (auto [val, cnt] : mp) {
        if (cnt > (n - 1) * n) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}