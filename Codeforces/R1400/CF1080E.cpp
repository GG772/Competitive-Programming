#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int m = 1e9 + 7;

void solve() {
    int n; cin >> n;
    
    vector<pair<int, int>> a(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector<ll> dp(n+1), cnt(n+1);
    auto dfs = [&](auto &&dfs, int cur) {
        if (a[cur].first == 0 && a[cur].second == 0) {
            return 0ll;
        }

        cnt[cur] = 4ll + dfs(dfs, a[cur].first) + dfs(dfs, a[cur].second);
        return cnt[cur];
    };

    auto add = [&](ll a, ll b) {
        return ((a % m) + (b % m)) % m;
    };

    dfs(dfs, 1);
    queue<pair<int, int>> q;
    q.push({1, 0});

    while (!q.empty()) {
        auto [cur, fa] = q.front();
        
        q.pop();
        if (cur == 0) {
            continue;
        }
        dp[cur] = add(1ll, add(cnt[cur], dp[fa]));
        if (a[cur].first != 0) {
            q.push(make_pair(a[cur].first, cur));
            q.push(make_pair(a[cur].second, cur));
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " \n"[i == n];
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    
}