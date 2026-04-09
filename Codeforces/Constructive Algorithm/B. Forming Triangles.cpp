// Problem: https://codeforces.com/problemset/problem/1922/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n; cin >> n;
    vector<int> a(n);
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll c = cnt[a[i]];
        ll tmp = 1ll * c * (c - 1);

        if (c >= 2) {
            ans += (1ll * tmp * max(0, i) / 2);
        }

        if (c >= 3) {
            ans += tmp * (c - 2ll) / 6ll;
        }

        int j = i;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        i = j - 1;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t; 
    while (t--) {
        solve();
    }
}