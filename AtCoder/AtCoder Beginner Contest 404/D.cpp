#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m; cin >> n >> m;

    vector<int> c(n);
    vector<vector<int>> a(n);

    for (int i = 0; i < n; i++) cin >> c[i];

    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            x--;
            a[x].push_back(i);
        }
    }

    ll ans = LLONG_MAX;

    for (ll i = 0; i < (1ll << n); i++) {
        for (ll j = 0; j < (1ll << n); j++) {
            vector<ll> cnt(m);

            ll tot = 0;

            for (int k = 0; k < n; k++) {
                ll t = ((i >> k) & 1) + ((j >> k) & 1);
                tot += t * c[k];
                if (t > 0) {
                    for (int x : a[k]) {
                        cnt[x] += t;
                    }
                }
            }
            
            bool f = true;
            for (int i = 0; i < m; i++) {
                f = f && cnt[i] >= 2;
                if (!f) break;
            }
            if (f) ans = min(ans, tot);
        }
        
    }

    cout << ans << "\n";
}