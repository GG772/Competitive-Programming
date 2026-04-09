#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m; cin >> n >> m;

    vector<int> a(n);

    set<int> lens;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        string tmp = to_string(a[i]);
        int sz = tmp.size();
        lens.insert(sz);
    }

    vector<ll> tpow(11, 1);
    for (int i = 1; i <= 10; i++) {
        tpow[i] = 10 * tpow[i-1];
    }

    map<ll, map<ll, ll>> mp;

    for (int i = 0; i < n; i++) {
        for (int exp : lens) {
            // cout << exp << " ";
            mp[exp][(((1ll * a[i]) % m) * (tpow[exp] % m)) % m]++;
        } 
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int exp = to_string(a[i]).size();
        int residue = m - (a[i] % m);
        if (a[i] % m == 0) residue = 0;
        ans += mp[exp][residue];
        // cout << mp[exp][residue] << " ";
    }

    cout << ans << "\n";
    
}