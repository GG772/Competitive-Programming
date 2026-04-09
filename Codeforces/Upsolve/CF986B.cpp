#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, b, c; cin >> n >> b >> c;

    if (b == 0 && c == 0) {
        if (n > 2) {
            cout << -1 << "\n";
            return;
        } 
    }

    ll cnt = 0;

    if (b > 0) {
        cnt = (n - 1 - c) / b;
        cnt = min(cnt, n);
        if (b * cnt + c <= n - 1) {
            cnt++;
        }
        
    } else {
        if (c == n-2 || c == n - 1) {
            cout << n-1 << "\n";
            return;
        } else if (c >= n) {
            cout << n << "\n";
            return;
        } else {
            cout << -1 << "\n";
            return;
        }
        
    }

    cnt = max(cnt, 0ll);
    cout << n - cnt << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}