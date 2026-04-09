#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> ans(n+1, -1);

    ans[n] = 1;
    
    vector<bool> vis(n+1);
    vis[1] = true;
    for (int i = 2; i < n; i += 2) {
        ans[i] = i + 1;
        vis[i+1] = true;
        if (i + 1 < n) {
            ans[i+1] = i;
            vis[i] = true;
        }
        // cout << (i ^ (i + 1)) << " ";
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans[1] = i;
            break;
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];

    // for (int i = 1; i <= n; i++) cout << (ans[i] ^ i) << " \n"[i == n];
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}