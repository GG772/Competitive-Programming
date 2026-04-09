#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> cnt(m);

    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int tmp; cin >> tmp;
            g[tmp - 1].push_back(i);
        }
        cnt[i] = k;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        b--;
        for (int dish : g[b]) {
            cnt[dish]--;
            if (cnt[dish] == 0) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}