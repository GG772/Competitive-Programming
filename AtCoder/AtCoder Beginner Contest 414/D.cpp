#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m; cin >> n >> m;

    vector<ll> a(n);

    for (ll &x : a) cin >> x;

    sort(a.begin(), a.end());

    vector<ll> d;

    for (int i = 1; i < n; i++) {
        d.push_back(a[i] - a[i-1]);
    }

    sort(d.begin(), d.end());   
    ll ans = 0;

    for (int i = 0; i < n - m; i++) {
        ans += d[i];
    }
    cout << ans << endl;
}