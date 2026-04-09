// Problem: https://codeforces.com/problemset/problem/1497/B
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    vector<int> cnt(m);
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        cnt[tmp % m]++;
    }

    int ans = 0;
    for (int i = 0; i <= m / 2; i++) {
        if (i != m - i && i != 0) {
            if (cnt[i] == 0 && cnt[m - i] == 0) {
                continue;
            }
            int ma = max(cnt[i], cnt[m-i]);
            int mi = min(cnt[i], cnt[m-i]);
            ans += 1 + (ma - mi < 2 ? 0 : ma - mi - 1);
            
        } else {
            if (cnt[i]) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t; 
    while (t--) {
        solve();
    }
}