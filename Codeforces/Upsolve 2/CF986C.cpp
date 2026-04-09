#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, v; cin >> n >> m >> v;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> pre(n+1);
    for (int i = 0; i < n; i++) pre[i+1] = pre[i] + a[i];

    vector<ll> L(m+1), R(m+1);
    for (int i = 1, j = 0; i <= m; i++) {
        while (j <= n && pre[j] - pre[L[i-1]] < v) j++;
        L[i] = j;
    }

    R[0] = n;
    for (int i = 1, j = n; i <= m; i++) {
        while (j >= 0 && pre[R[i-1]] - pre[j] < v) j--;
        R[i] = j;
    }

    ll ans = -1;
    for (int i = 0; i <= m; i++) {
        if (L[i] <= R[m - i]) {
            ans = max(ans, pre[R[m - i]] - pre[L[i]]);
        }
    }
    cout << ans << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
}
