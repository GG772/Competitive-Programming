#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    ll s = accumulate(a.begin(), a.end(), 0ll);
    vector<ll> pre(n+1, 0);

    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + a[i];
    }

    int need = 0;
    while (pre[need] < s / 2) {
        need++;
    }

    cout << need + (s + 1) / 2 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}