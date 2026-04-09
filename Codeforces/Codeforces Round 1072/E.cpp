#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n; cin >> n;

    vector<int> a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> ind(n+1);
    for (int i = 1; i < n; i++) {
        ind[abs(a[i] - a[i-1])].push_back(i);
    }

    ll ans = n * (n - 1) / 2;
    set<int> st;
    st.insert(0);
    st.insert(n);

    for (int i = 1; i < n; i++) {
        cout << ans << " \n"[i == n - 1];
        for (ll id : ind[i]) {
            ll r = *st.upper_bound(id);
            ll l = *--st.upper_bound(id);
            
            ans -= (r - l) * (r - l - 1) / 2;
            ans += (id - l) * (id - l - 1) / 2 + (r - id) * (r - id - 1) / 2;
            st.insert(id);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}