#include <bits/stdc++.h>

using namespace std; 

void solve() {
    int n, k, q; cin >> n >> k >> q;
    vector<int> ans(n, 1000);
    vector<int> mark(n);
    vector<pair<int, int>> query;

    for (int i = 0; i < q; i++) {
        int c, l, r; cin >> c >> l >> r;
        l--, r--;
        
        if (c == 1) {
            for (int j = l; j <= r; j++) {
                if (mark[j] == 0) mark[j] = 1;
            }
        } else {
            query.push_back({l, r});
        }
    }

    for (auto [l, r] : query) {
        for (int j = l; j <= r; j++) {
            if (mark[j] == 0) mark[j] = 2;
            else if (mark[j] == 1) mark[j] = 3;
        }
    }

    int ptr = 0;
    for (int i = 0; i < n; i++) {
        if (mark[i] == 1) ans[i] = k;
        else if (mark[i] == 2) {
            ans[i] = ptr;
            ptr = (ptr + 1) % k;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
    
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}