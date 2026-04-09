#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    for (auto &[_, v] : cnt) {
        if (v >= 2) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
