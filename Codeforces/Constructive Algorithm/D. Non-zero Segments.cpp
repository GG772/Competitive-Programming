#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];


    vector<ll> pre(n+1);

    map<ll, bool> mp;

    ll s = 0;
    int ans = 0;
    mp[0] = true;
    bool f = true;
    for (int i = 0; i < n; i++) {
        s += a[i];
        if (mp.count(s)) {
            ans++;
            mp.clear();
            mp[0] = true;
            s = a[i];
        }
        mp[s] = true;
        
    }

    cout << ans << endl;

    
}

int main() {
    solve();
}