#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n);
    vector<ll> pre(n+1), pmax(n+1, 0), smax(n+1, n - 1);

    for (int i = 0; i < n; i++) cin >> a[i];

    a[0] += c;

    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + a[i];
        if (a[i] > a[pmax[i]]) {
            pmax[i+1] = i;
        } else {
            pmax[i+1] = pmax[i];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] >= a[smax[i+1]]) {
            smax[i] = i;
        } else {
            smax[i] = smax[i+1];
        }
    }

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        if (pmax[i + 1] == i && smax[i] == i) {
            continue;
        } else if (pre[i+1] >= a[smax[i]]) {
            ans[i] = i;
        } else {
            ans[i] = i + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}