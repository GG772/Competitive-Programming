#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    bool b1 = true, b2 = true;
    for (int i = 0; i < n; i++) {
        b1 = b1 && (a[i] == b[i]);
        b2 = b2 && (a[i] != b[i]);
    }
    
    if (b1) {
        cout << "YES\n";
        return;
    } else if (!b2) {
        cout << "NO\n";
        return;
    }
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }
}