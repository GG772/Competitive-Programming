#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;

    int block = 0;
    string t = "";

    vector<int> cnt(26);

    auto chk = [&]() -> bool {
        for (int i = 0; i < k; i++) {
            if (cnt[i] < 1) {
                return false;
            }
        }
        return true;
    };

    for (int i = 0; i < m; i++) {
        cnt[s[i] - 'a']++;
        if (chk()) {
            block++;
            t.push_back(s[i]);
            for (int j = 0; j < 26; j++) {
                cnt[j] = 0;
            }
        }
    }

    if (block < n) {
        cout << "No\n";
        for (int i = 0; i < k; i++) {
            if (cnt[i] < 1) {
                while (int(t.size()) < n) {
                    t.push_back(char(i + 'a'));
                }
                cout << t << "\n";
                return;
            }
        }
    } else {
        cout << "Yes\n";
    }

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}