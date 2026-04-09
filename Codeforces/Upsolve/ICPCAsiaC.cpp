#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();

    map<char, vector<int>> mp;

    for (int i = 0; i < m - 1; i++) {
        mp[t[i]].push_back(i);
    }

    int len = 2 * (n + m);

    string ans = "";

    for (int i = 1; i < n; i++) {
        if (!mp.count(s[i])) continue;

        int j = mp[s[i]].back();

        if (i + m - j < len) {
            len = i + m - j;
            ans = s.substr(0, i + 1) + t.substr(j+1);
        }

    }

    if (len == 2 * (n + m)) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}

int main() {
    int t; t = 1;

    while (t--) solve();
}