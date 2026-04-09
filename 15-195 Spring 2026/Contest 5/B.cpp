#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<tuple<int, int, int>> a(n);

    vector<int> ends;

    for (int i = 0; i < n; i++) {
        int x, y, p; cin >> x >> y >> p;
        a[i] = {x, y, p};
        ends.push_back(y);
    }

    sort(a.begin(), a.end(), [](tuple<int, int, int> x, tuple<int, int, int> y) {
        auto [x1, x2, x3] = x;
        auto [y1, y2, y3] = y;
        return x2 < y2;
    });

    sort(ends.begin(), ends.end());

    vector<ll> dp(n+1);
    for (int i = 0; i < n; i++) {
        auto [x, y, p] = a[i];
        int prev = upper_bound(ends.begin(), ends.end(), x - 1) - ends.begin();
        dp[i+1] = max(dp[i], dp[prev] + 1ll * p);
    }

    cout << dp[n] << "\n";
}