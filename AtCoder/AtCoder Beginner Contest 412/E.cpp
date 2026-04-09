#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll N = 1e7 + 5;


void solve() {
    ll l, r; cin >> l >> r;
    // vis records whether number in range [l, r] is a prime or not
    vector<bool> vis(N), isPrime(N, true);

    int ans = 0;

    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            ll lo = ((l + 1 + i - 1) / i) * i;
            for (ll L = lo; L <= r; L += i) {
                // number L is a multiple of prime number i in range [l, r]
                vis[L - l] = true;
                ll t = L;
                while (t % i == 0) {
                    t /= i;
                }
                if (t == 1) ans++;
            }

            for (int start = 2 * i; start < N; start += i) {
                isPrime[start] = false;
            }
        }
    }

    for (ll i = l; i <= r; i++) {
        ans += (!vis[i - l]);
    }

    cout << ans << "\n";
}

int main() {
    int t; t = 1;
    while (t--) solve();
}