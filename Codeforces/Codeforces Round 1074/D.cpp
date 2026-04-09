#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n);
    vector<pair<ll, int>> b(n);

    int ver = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = make_pair(a[i], ver);
    }

    for (int i = 0; i < m; i++) {
        int c, d; cin >> c >> d;
        

    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}