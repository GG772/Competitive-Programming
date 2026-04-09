#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, x, y; cin >> a >> x >> y;
    if (min(x, y) <= a && a <= max(x, y)) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}