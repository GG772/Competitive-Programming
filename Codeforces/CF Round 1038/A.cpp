#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    if (n == 1 || m == 1) cout << "NO\n";
    else if (n == 2 && m == 2) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}