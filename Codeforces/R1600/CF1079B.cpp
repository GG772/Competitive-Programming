// https://codeforces.com/contest/2196/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int threshold = 1;
    while (threshold * threshold < n) threshold++;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= threshold) {
            for (ll j = a[i]; i + j < n; j += a[i]) {
                if (a[i] * a[i + j] == j) {
                    ans++;
                }
            }
            for (ll j = a[i]; i - j >= 0; j += a[i]) {
                if (a[i] * a[i - j] == j) {
                    ans++;
                }
            }
        } else {
            int cnt = 0;
            for (ll j = a[i]; i + j < n && j / a[i] < threshold; j += a[i], cnt++) {
                if (a[i] * a[i + j] == j) {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}