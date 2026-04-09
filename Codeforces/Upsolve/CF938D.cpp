#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);

    for (int &x : a) cin >> x;

    map<int, int> mp;

    for (int &x : b) {
        cin >> x;
        mp[x]++;
    }

    int ans = 0, match = 0, l = 0;
    for (int i = 0; i < n; i++) {
        if (mp.count(a[i])) {
            mp[a[i]]--;
            if (mp[a[i]] >= 0) {
                match++;
            }
        }
        
        if (i < m - 1) continue;
        ans += match >= k;

        if (mp.count(a[l])) {
            mp[a[l]]++;
            if (mp[a[l]] > 0) {
                match--;
            }
        }
        
        l++;
    }
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}