#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());
    vector<ll> pre(n+1);

    for (int i = 0; i < n; i++) pre[i+1] = pre[i] + a[i];

    for (int i = 0; i < q; i++) {
        int b; cin >> b;
        int ind = lower_bound(a.begin(), a.end(), b) - a.begin();

        if (ind == n) {
            cout << -1 << endl;
            continue;
        }

        ll lo = pre[ind];
        ll ans = 1ll * (b-1) * (n - ind) + 1ll * lo + 1;
        if (ans < b || ans > pre[n]) {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;

    }
}