#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t; cin >> s >> t;

    map<char, int> cnt;
    vector<string> ans;
    for (char c : s) cnt[c]--;
    for (char c : t) cnt[c]++;

    int ptr = 0, n = s.length();

    for (auto [l, c] : cnt) {
        if (c < 0) {
            cout << "Impossible\n";
            return;
        } else if (c == 0) {
            continue;
        }

        string tmp = string(c, l);
        string tmp2 = "";

        while (ptr < n && s[ptr] <= tmp[0]) {
            tmp2 += string(1, s[ptr]);
            ptr++;
        }

        tmp = tmp2 + tmp;

        ans.push_back(tmp);
    }

    for (string s : ans) cout << s;
    for (int i = ptr; i < n; i++) {
        cout << s[i];
    }
    cout << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}