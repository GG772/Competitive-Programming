#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; 
    ll m; cin >> n >> m;

    if (1ll * n * (n + 1) / 2 < m) {
        cout << -1 << "\n";
        return;
    } else if (n == 1 && m > 1) {
        cout << -1 << "\n";
        return;
    } else if (m < n * 1ll) {
        cout << -1 << "\n";
        return;
    }

    ll base = n, tmp = n - 1;
    while (base < m) {
        base += tmp;
        tmp--;
    }

    vector<int> vis(n+1, -1);
    int root = n - tmp;
    int cur = n;
    while (base > m && cur >= 1) {
        if (cur == root) continue;
        if (base - min(cur, root) + 1 >= m) {
            vis[cur] = 1;
            base = base - min(cur, root) + 1;
        } else {
            vis[cur] = base - m + 1;
            base = m;
            break;
        } 

        if (cur < 1 || base == m) break;
        cur--;
    } 

    cout << root << "\n";
    for (int i = 1; i <= n; i++) {
        if (i == root) continue;
        if (vis[i] == -1) {
            cout << root << " " << i << "\n";
        } else {
            cout << i << " " << vis[i] << "\n";
        }
    }


}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}