#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y; cin >> x >> y;
    
    int d = 0;
    if (y < 0) d = abs(4 * y);
    else d = 2 * y;

    if (x < d || (x - d) % 3 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}