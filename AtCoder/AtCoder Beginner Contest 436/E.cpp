#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    ll ans = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[p[i]]) continue;
        vis[p[i]] = true;

        int cur = p[i];
        int cnt = 1;
        while (!vis[p[cur]]) {
            vis[p[cur]] = true;
            cur = p[cur];
            cnt++;
        }
        ans += 1ll * cnt * (cnt - 1) / 2;
    }

    cout << ans << "\n";
}