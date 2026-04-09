#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> f(n);

    for (int i = 0; i < n; i++) cin >> f[i];

    vector<ll> ans(n);

    for (int i = 1; i < n - 1; i++) {
        ans[i] = (f[i+1] - 2 * f[i] + f[i-1]) / 2;
    }

    ll cur = f[0];
    for (int i = 1; i < n - 1; i++) {
        cur -= (1ll * i) * ans[i];
    }
    ans[n-1] = cur / (n - 1);

    cur = f[1] - f[0];
    for (int i = 1; i < n; i++) {
        cur += ans[i];
    }

    ans[0] = cur;
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}