#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    cout << min({a, c, b + (a + c - 2 * b) / 3}) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    
}