#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 998244353;
const int inv2 = (mod + 1) / 2;

int main() {
    ll n; cin >> n;

    int p1 = 1ll * ((((n % mod) * ((n + 1) % mod)) % mod) * (inv2 % mod)) % mod;
    int p2 = 0;
    for (ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);

        int len = (r - l + 1) % mod;
        int val = (1ll * n / l) % mod;

        p2 = (p2 + (1ll * len * val) % mod) % mod;
    }

    cout << (1ll * p1 - p2 + mod) % mod << endl;
}