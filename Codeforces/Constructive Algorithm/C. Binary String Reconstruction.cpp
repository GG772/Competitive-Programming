#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int x; cin >> x;

    int n = s.length();
    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++) {
        if (s[i] - '0' == 0) {
            if (i >= x) {
                ans[i-x] = 0;
            } 

            if (i + x < n) {
                ans[i+x] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] - '0' == 1) {
            int cnt0 = (i >= x && ans[i-x] == 1);
            int cnt1 = (i + x < n && ans[i+x] == 1);
            if (cnt0 + cnt1 < 1) {
                cout << -1 << endl;
                return;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }

    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}