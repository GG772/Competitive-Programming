#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    string s; cin >> s;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') cnt++;
        else cnt = 0;
        if (cnt == k) {
            cout << "NO\n";
            return;
        }
    }

    vector<int> ans(n);

    cnt = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ans[i] = cnt++;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') ans[i] = cnt++;
    }

    cout << "YES\n";

    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}