#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, x; cin >> n >> x;
    ll k; cin >> k;
    string s; cin >> s;

    // first time to reach 0
    int t = 0;
    while (x != 0 && t < n) {
        x -= s[t] == 'L';
        x += s[t] == 'R';
        t++;
    }

    int t2 = 1;
    int cur = s[0] == 'L' ? -1 : 1;
    while (cur != 0 && t2 < n) {
        cur -= s[t2] == 'L';
        cur += s[t2] == 'R';
        t2++;
    }

    if (x != 0 || k < t) {
        cout << 0 << endl;
        return;
    } else if (cur != 0) {
        cout << 1 << endl;
        return;
    }

    ll ans = 1;
    k -= t;
    ans += k / t2;
    cout << ans << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}