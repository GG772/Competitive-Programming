// extra practice for trie: 
// https://www.luogu.com.cn/problem/P8306
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e6 + 5;
int delta[MAXN][62];
vector<int> cnt(MAXN);
int tot;

int get(char c) {
    if ('a' <= c && c <= 'z') return c - 'a';
    if ('A' <= c && c <= 'Z') return 26 + (c - 'A');
    return 52 + (c - '0');
}

void solve() {
    for (int i = 0; i <= tot; i++) {
        cnt[i] = 0;
        memset(delta[i], 0, sizeof(delta[i]));
    }
    tot = 0;
    
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int cur = 0;
        for (char c : s) {
            int id = get(c);
            if (!delta[cur][id]) {
                ++tot;
                delta[cur][id] = tot;
                cur = tot;
            } else {
                cur = delta[cur][id];
            }
            cnt[cur]++;
        }
    }

    for (int i = 0; i < q; i++) {
        string s; cin >> s;
        int cur = 0;
        bool f = true;
        for (char c : s) {
            int id = get(c);
            if (!delta[cur][id]) {
                cout << 0 << "\n";
                f = false;
                break;
            } else {
                cur = delta[cur][id];
            }
        }

        if (f) cout << cnt[cur] << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}