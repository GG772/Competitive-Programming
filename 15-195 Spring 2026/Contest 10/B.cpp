#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; ll k; cin >> n >> k;
    vector<ll> a(2 * n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n; i < 2 * n; i++) {
        a[i] = a[i - n];
    }

    vector<ll> next(n, n);
    int l = 0;
    ll tot = 0;
    for (int i = 0; i < 2 * n; i++) {
        tot += a[i];
        while (tot > k && l < i) {
            if (l < n) {
                next[l] = i - l;
            }
            
            tot -= a[l++];
        }
    }

    vector<vector<ll>> dp2(n, vector<ll>(20));
    for (int i = 0; i < n; i++) {
        dp2[i][0] = next[i];
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < n; i++) {
            ll nxt = (1ll * i + (dp2[i][j-1] % n)) % n;
            dp2[i][j] = dp2[i][j-1] + dp2[nxt][j-1];
        }
    }

    int ans = n;
    for (int i = 0; i < n; i++) {
        ll cur = i;
        int cand = 0;
        for (int j = 19; j >= 0; j--) {
            if (cur + dp2[cur % n][j] < n + i) {
                cur += dp2[cur % n][j];
                cand += (1 << j);
            }
        }

        ans = min(ans, cand + 1);
    }

    cout << ans << "\n";
}