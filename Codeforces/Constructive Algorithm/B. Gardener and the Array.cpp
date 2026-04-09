// Problem: https://codeforces.com/problemset/problem/1775/B

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
vector<int> p[N];

void solve() {
    int n; cin >> n;
    
    map<int, int> cnt;

    for (int j = 0; j < n; j++) {
        p[j].clear();
    }

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            
            int tmp; cin >> tmp;
            cnt[tmp]++;
            p[i].push_back(tmp);
        }
    }

    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < p[i].size(); j++) {
            if (cnt[p[i][j]] - 1 == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "yes\n";
            return;
        }
    }

    cout << "no\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}