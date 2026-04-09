#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, x; cin >> n >> x;

    for (int i = 0; i < x; i++) {
        cout << i << " ";
    }

    for (int i = n - 1; i > x; i--) {
        cout << i << " ";
    }

    if (x < n) cout << x << "\n";
    else cout << "\n";

    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}