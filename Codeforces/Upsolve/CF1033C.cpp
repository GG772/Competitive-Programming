#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n, m; cin >> n >> m;

    ll l = n, r = n * (n + 1) / 2;
    
    if (m < l || m > r) {
        cout << -1 << "\n";
        return;
    }

    vector<int> taken(n+1);

    int root = -1;
    ll p = m - n;
    for (int i = n; i >= 1; i--) {
        if (p >= i - 1) {
            p -= i - 1;
            taken[i] = 1;
            root = max(root, i);
        }
    }

    cout << root << "\n";

    for (int i = 1; i <= n; i++) {
        if (i == root) continue;

        if (i == 1) {
            cout << root << " " << i << "\n";
        } else if (taken[i]) {
            cout << root << " " << i << "\n";
        } else {
            cout << 1 << " " << i << "\n";
        }
    }

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}