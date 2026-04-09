#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> b(n);

    for (int i = 0; i < n; i++) cin >> b[i];

    int mn = INT_MAX / 2;
    bool f = true;
    for (int i = 0; i < n; i++) {
        if (b[i] >= mn * 2) f = false;
        mn = min(mn, b[i]);
    }

    if (f) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}