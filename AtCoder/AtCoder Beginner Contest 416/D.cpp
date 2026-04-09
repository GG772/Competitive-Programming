#include <bits/stdc++.h>

using namespace std;

using ll = long long;
void solve() {
    int n, m; cin >> n >> m;

    vector<ll> a(n), b(n);

    ll s = 0;
    for (ll &x : a) {
        cin >> x;
        s += x;
    }

    for (ll &x : b) {
        cin >> x;
        s += x;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int p1 = n - 1;
    int p2 = lower_bound(b.begin(), b.end(), m - a[p1]) - b.begin();
    if (p2 == n) {
        cout << s << endl;
        return;
    }

    ll ans = 0;
    vector<bool> unused(n, true);
    while (p1 >= 0) {
        while (p2 < n && a[p1] + b[p2] < m) {
            p2++;
        }

        if (p2 < n) {
            unused[p2] = false;
            ans += a[p1] + b[p2] - m;
            p1--, p2++;
        } else {
            break;
        }
    }

    int j = 0;
    for (int i = 0; i <= p1; i++) {
        while (j < n && !unused[j]) {
            j++;
        }
        unused[j] = false;
        ans += a[i] + b[j];
    }

    cout << ans << endl;

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}   