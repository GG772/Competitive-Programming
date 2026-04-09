#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y, z; cin >> x >> y >> z;
    int a = x & y, b = y & z, c = x & z;

    if (a == b && b == c) cout << "YES\n";
    else cout << "NO\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}