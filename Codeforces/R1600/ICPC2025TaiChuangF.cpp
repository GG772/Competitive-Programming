// https://codeforces.com/contest/2181/problem/F

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n), pre(n), suf(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = gcd(pre[i-1], a[i]);
    }

    suf[n-1] = a[n-1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = gcd(suf[i+1], a[i]);
    }

    ll ans = pre[n-1];

    for (int i = 1; i < n - 1; i++) {
        ans += min(pre[i], suf[i]);
    }

    cout << ans << "\n";
}

int main() {
    int t; t = 1;
    while (t--) solve();
}