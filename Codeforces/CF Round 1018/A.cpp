#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> ans(n);
    
    int mn = 1, mx = n;

    for (int i = n - 1; i >= 0; i--) {
        int cur = 0;
        if (s[i-1] == '>') {
            cur = mx;
            mx--;
        } else {
            cur = mn;
            mn++;
        }
        ans[i] = cur;
    }

    ans[0] = mx;

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}