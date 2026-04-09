#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = "0" + s;

    vector<bool> dp(s.length());

    dp[0] = true;
    
    for (int i = 0; i < s.length(); i++) {
        if (!dp[i]) continue;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) continue;
            if ((i | (1 << j)) <= s.length() && s[i | (1 << j)] == '0') {
                dp[i | (1 << j)] = dp[i];
            }
        }
    }
    int l = s.length();
    if (dp[l - 1]) cout << "Yes\n";
    else cout << "No\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}