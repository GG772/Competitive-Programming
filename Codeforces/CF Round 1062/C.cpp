#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    int n; ll x;
    cin >> n >> x;    

    vector<ll> a(n);

    for (ll &x : a) cin >> x;
    sort(a.begin(), a.end());

    int l = 0, r = n - 1;
    vector<ll> ans;

    ll s = 0;
    ll tot = 0;
    while (l <= r) {
        if ((s + a[r]) / x > (s / x)) {
            ans.push_back(a[r]);
            tot += a[r];
            s += a[r];
            r--;
        } else {
            ans.push_back(a[l]);
            s += a[l++];
        }
    }

    cout << tot << "\n";
    int m = ans.size();
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
    }
}

int main() {
    int t; cin >> t;
    while (t--){
        solve();
    }
}