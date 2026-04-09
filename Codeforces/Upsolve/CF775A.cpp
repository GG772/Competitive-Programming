#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> row(N), col(N);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            x--;
            row[x].push_back(i);
            col[x].push_back(j);
        }
    }

    ll ans = 0;

    auto count = [&](vector<int> &a) -> ll {
        if (a.size() == 0) return 0ll;
        sort(a.begin(), a.end());
        ll s = 0;
        int len = a.size();
        ll res = 0;
        for (int i = 0; i < len; i++) {
            res += 1ll * a[i] * i - s;
            s += a[i];
        }

        return res;
    };

    for (int i = 0; i < N; i++) {
        ans += count(row[i]);
        ans += count(col[i]);
    }

    cout << ans << "\n";
}

int main() {
    int t; t = 1;
    while (t--) solve();
    
}

