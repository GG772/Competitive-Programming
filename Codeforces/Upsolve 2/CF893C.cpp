#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<bool> vis(n+1);
    vector<int> ans;

    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            for (int j = i; j <= n; j += i) {
                if (!vis[j]) ans.push_back(j);
                vis[j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) ans.push_back(i);
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}