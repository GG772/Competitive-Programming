// Problem: https://codeforces.com/contest/2052/problem/A

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> ans;
    vector<bool> vis(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = a[i] - 1; j >= 1; j--) {
            if (vis[j]) continue;
            ans.push_back({a[i], j});
        }

        for (int j = 1; j <= n; j++) {
            if (j == a[i] || vis[j]) continue;
            ans.push_back({j, a[i]});
        }

        vis[a[i]] = true;
    }

    cout << ans.size() << "\n";
    for (auto [k, v] : ans) {
        cout << k << " " << v << "\n";
    }
}

int main() {
    int t; t = 1;
    while (t--) solve();
}