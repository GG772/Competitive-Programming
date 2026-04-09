#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    set<int> s, t;
    vector<int> ans;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    for (int x : s) {
        if (t.count(x)) continue;
        for (int j = 2 * x; j <= k; j += x) {
            if (!s.count(j)) {
                cout << -1 << "\n";
                return;
            }
            t.insert(j);
        }
        ans.push_back(x);
        t.insert(x);
        
    }

    int m = ans.size();
    cout << m << "\n";
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m-1];
    }



    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}