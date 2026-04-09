#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, x, y; cin >> n >> x >> y;

    string s; cin >> s;
    vector<int> p(n);

    ll ss = 0;
    for (int &x : p) {
        cin >> x;
        ss += x;
    }

    if (x + y < ss) {
        cout << "NO\n";
        return;
    }
    
    int lo1 = 0, lo2 = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            lo1 += p[i] / 2 + 1;
            cnt1++;
        } else {
            lo2 += p[i] / 2 + 1;
            cnt2++;
        }
    }

    if (cnt1 == n) {
        if (x < y + n) {
            cout << "NO\n";
            return;
        }
    }
    
    if (cnt2 == n) {
        if (y < x + n) {
            cout << "NO\n";
            return;
        }
    }

    if (x < lo1 || y < lo2) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}