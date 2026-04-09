#include <bits/stdc++.h>

using namespace std;

void solve() {
    int s, k, m; cin >> s >> k >> m;

    if ((m / k) % 2 == 0) {
        cout << max(0, s - (m % k)) << "\n";
    } else {
        cout << max(0, min(s, k) - (m % k)) << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}