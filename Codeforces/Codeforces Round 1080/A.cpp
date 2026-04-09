#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    bool f = false;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        f = f || (x == 67);
    }
    if (f) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}