// https://codeforces.com/contest/2193/problem/F
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1e9 + 5;

void solve() {
    int n; cin >> n;
    ll ax, ay, bx, by; cin >> ax >> ay >> bx >> by;

    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    map<ll, ll> mn, mx;
    map<ll, bool> used;
    for (int i = 0; i < n; i++) {
        if (!mn.count(a[i])) {
            mn[a[i]] = inf;
        }
        if (!mx.count(a[i])) {
            mx[a[i]] = -inf;
        }
        mn[a[i]] = min(mn[a[i]], b[i]);
        mx[a[i]] = max(mx[a[i]], b[i]);
    }

    sort(a.begin(), a.end());
    map<ll, array<ll, 2>> dp;
    ll l = ay, r = ay, level = ax;

    dp[level] = {0, 0};

    for (int i = 0; i < n; i++) {
        if (used[a[i]]) continue;
        used[a[i]] = true;
        if (!dp.count(a[i])) dp[a[i]] = {0, 0};
        ll dl1 = abs(l - mn[a[i]]), dr1 = abs(l - mx[a[i]]);
        ll dl2 = abs(r - mn[a[i]]), dr2 = abs(r - mx[a[i]]);

        if (mn[a[i]] <= l && l <= mx[a[i]]) {
            dp[a[i]][0] = 2ll * dr1 + dl1 + abs(level - a[i]) + dp[level][0];
            dp[a[i]][1] = 2ll * dl1 + dr1 + abs(level - a[i]) + dp[level][0];
        } else if (l < mn[a[i]]) {
            dp[a[i]][0] = 2ll * dr1 - dl1 + abs(level - a[i]) + dp[level][0];
            dp[a[i]][1] = dr1 + abs(level - a[i]) + dp[level][0];
        } else {
            dp[a[i]][0] = dl1 + abs(level - a[i]) + dp[level][0];
            dp[a[i]][1] = 2ll * dl1 - dr1 + abs(level - a[i]) + dp[level][0];
        }

        if (mn[a[i]] <= r && r <= mx[a[i]]) {
            dp[a[i]][0] = min(dp[a[i]][0], 2ll * dr2 + dl2 + abs(level - a[i]) + dp[level][1]);
            dp[a[i]][1] = min(dp[a[i]][1], 2ll * dl2 + dr2 + abs(level - a[i]) + dp[level][1]);
        } else if (r < mn[a[i]]) {
            dp[a[i]][0] = min(dp[a[i]][0], 2ll * dr2 - dl2 + abs(level - a[i]) + dp[level][1]);
            dp[a[i]][1] = min(dp[a[i]][1], dr2 + abs(level - a[i]) + dp[level][1]);
        } else {
            dp[a[i]][0] = min(dp[a[i]][0], dl2 + abs(level - a[i]) + dp[level][1]);
            dp[a[i]][1] = min(dp[a[i]][1], 2ll * dl2 - dr2 + abs(level - a[i]) + dp[level][1]);
        }

        level = a[i];
        l = mn[a[i]];
        r = mx[a[i]];
    }


    ll ans = min(
        dp[level][0] + abs(level - bx) + abs(l - by),
        dp[level][1] + abs(level - bx) + abs(r - by)
    );

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}