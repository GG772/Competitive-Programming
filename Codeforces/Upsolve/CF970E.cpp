#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n == 1) {
        cout << 1 << "\n";
        return;
    } else if (n == 2) {
        cout << 0 << "\n";
        return;
    }

    map<int, vector<int>> mp;

    for (int i = 0; i < 26; i++) {
        char c = char('a' + i);
        mp[i].resize(n + 1);
        for (int j = 0; j < n; j++) {
            int prev = 0;
            if (j - 1 >= 0) prev = mp[i][j-1];
            mp[i][j + 1] = prev + (s[j] == c);
        }
    }

    int ans = 0;
    if (n % 2 == 0) {
        int mx1 = 0, mx2 = 0;
        for (int i = 0; i < 26; i++) {
            mx1 = max(mx1, mp[i][n]);
            mx2 = max(mx2, mp[i][n - 1]);
        }
        cout << n - mx1 - mx2 << "\n";
    } else {
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            int mx1 = (n - 1) / 2, mx2 = (n - 1) / 2;
            for (int j = 0; j < 26; j++) {
                int cnt1 = 0;
                int l1 = 0;
                if (i >= 1) {
                    l1 = mp[j][i - 1];
                }
                if ((i + 1) % 2 == (n - 1) % 2) {
                    cnt1 = mp[j][n] - mp[j][i] + l1;
                } else {
                    cnt1 = mp[j][n] - mp[j][i + 1] + mp[j][i];
                }
                
                mx1 = min(mx1, (n - 1) / 2 - cnt1);
            }

            for (int k = 0; k < 26; k++) {
                int cnt2 = 0;
                int l2 = 0;
                if (i >= 1) {
                    l2 = mp[k][i - 1];
                }
                if ((i + 1) % 2 == (n - 1) % 2) {
                    cnt2 = mp[k][n-1] - mp[k][i + 1] + mp[k][i];
                } else {
                    cnt2 = mp[k][n-1] - mp[k][i] + l2;
                }
                
                mx2 = min(mx2, (n - 1) / 2 - cnt2);
            }

            ans = min(ans, mx1 + mx2 + 1);
        }

        cout << ans << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}