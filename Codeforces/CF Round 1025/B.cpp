#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<pair<int, int>> g = {{a, m}, {n, b}, {n - a + 1, m}, {n, m - b + 1}};

    int ans = INT_MAX / 2;
    for (auto &[x, y] : g) {
        int res = 0;
        while (x > 1) {
            res++;
            x = (x + 1) / 2;
        }

        while (y > 1) {
            res++;
            y = (y + 1) / 2;
        }

        ans = min(ans, res + 1);
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}