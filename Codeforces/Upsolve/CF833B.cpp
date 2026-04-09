#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = n;

    for (int k = 2; k <= 100; k++) {
        if (k > n) break;

        vector<int> cnt(10);
        int l = 0;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            cnt[s[i] - '0']++;
            if (cnt[s[i] - '0'] == 1) tot += 1;
            if (i < k - 1) continue;
            int mx = 0;
            for (int x : cnt) {
                mx = max(mx, x);
            }

            ans += (mx <= tot);
            cnt[s[l] - '0']--;
            if (cnt[s[l] - '0'] == 0) tot -= 1;
            l++;
        }
    }
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}