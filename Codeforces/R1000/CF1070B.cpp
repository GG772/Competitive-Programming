// https://codeforces.com/problemset/problem/2193/C

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    int last = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        int j = (i % n);
        if (s[j] == '1') last = i;
        else ans = max(ans, i - last);
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}