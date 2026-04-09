#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; string s; cin >> n >> s;
    int sum = 0;

    vector<int> c(n+1);
    for (int i = 0; i < n; i++) {
        c[i+1] = c[i] + (s[i] == '0' ? 1 : -1);
        sum += (s[i] == '1');
    } 

    int mx = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = min(ans, c[i+1] - mx);
        mx = max(mx, c[i+1]);
    }

    cout << ans + sum << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

