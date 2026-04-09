#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n; cin >> n;

    vector<ll> ans;

    for (int i = 62; i >= 0; i--) {
        ll x = 1ll << i;

        if (((x & n) == x) && (x != n)) {
            ans.push_back(n - x);
        }
    }

    ans.push_back(n);
    cout << ans.size() << "\n";
    for (ll x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t; cin >> t; 
    while (t--) {
        solve();
    }
}