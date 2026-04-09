#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5005;

int main() {
    int t; cin >> t;
    int M; cin >> M;

    auto add = [&](ll x, ll y) {
        return ((x % M) + (y % M)) % M;
    };

    auto mul = [&](ll x, ll y) {
        return ((x % M) * (y % M)) % M;
    };

    vector<vector<ll>> binom(N, vector<ll>(N));

    binom[0][0] = 1;

    for (int i = 1; i < N; i++) {
        binom[i][0] = 1;
        binom[i][i] = 1;
        for (int j = 1; j < i; j++) {
            binom[i][j] = add(binom[i-1][j], binom[i-1][j-1]);
        }
    }

    auto solve = [&]() {
        int n; cin >> n;
        vector<int> a(n);

        ll s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        
        ll res = 1;
        for (int i = 0; i < n; i++) {
            res = mul(res, binom[s][a[i]]);
            s -= a[i];
        }

        cout << res << "\n";
    };
    
    while (t--) {
        solve();
    }
}