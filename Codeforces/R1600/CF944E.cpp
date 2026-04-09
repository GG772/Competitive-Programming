#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    vector<ll> a(k+1), b(k+1);

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < q; i++) {
        ll d; cin >> d;

        auto it = upper_bound(a.begin(), a.end(), d);
        --it;

        int ind = it - a.begin();
        
        ll ans = b[ind];
        if (ind < k) {
            // cout << "speed: " << speed << "\n";
            ll dist = (1ll * d - a[ind]) * (1ll * b[ind + 1] - b[ind]) / (1ll * a[ind+1] - a[ind]);

            ans += dist;
        }

        cout << ans << " \n"[i == q-1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
