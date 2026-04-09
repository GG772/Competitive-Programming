// Problem: https://codeforces.com/problemset/problem/2003/C

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> cnt(26);
    vector<int> cnt2(26);
    int ind = 0;
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
        if (cnt[ind] < cnt[s[i] - 'a']) {
            ind = s[i] - 'a';
        }
        cnt2[s[i] - 'a']++;
    }

    sort(cnt2.begin(), cnt2.end());

    int diff = cnt[ind] - cnt2[24];
    string ans = "";
    while (diff > 0) {
        ans.push_back('a' + ind);
        cnt[ind]--;
        diff--;
    }


    while (cnt[ind]) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                ans.push_back(i + 'a');
                cnt[i]--;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}