#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
    ll N = 1e6 + 5;
    vector<ll> cnt(N), ans(N);

    for (ll i = 2; i <= N; i++) {
        if (cnt[i] == 0) {
            for (ll j = i; j <= N; j += i) {
                cnt[j]++;
            }
        }
    }

    ll cur = 0;
    for (ll i = 2; i <= N; i++) {
        if (cnt[i] == 2) {
            cur = i;
        }

        ans[i] = cur;
    }

    ll q; cin >> q;
    while (q--) {
        ll x; cin >> x;
        ll tmp = sqrtl(x);
        cout << ans[tmp] * ans[tmp] << "\n";
    }


}