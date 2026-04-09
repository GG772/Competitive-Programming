#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    
    int pos1 = 0, posn = 0;

    for (int i = 0; i < n; i++) {
        cin >> p[i];

        if (p[i] == 1) pos1 = i + 1;
        if (p[i] == n) posn = i + 1;
    }

    string x; cin >> x;

    if (x[0] == '1' || x.back() == '1' || x[pos1-1] == '1' || x[posn-1] == '1') {
        cout << -1 << "\n";
        return;
    }

    vector<pair<int, int>> ans;

    if (pos1 < posn) {
        if (1 < pos1) {
            ans.push_back({1, pos1});
            ans.push_back({1, posn});
        }
        
        ans.push_back({pos1, posn});
        if (posn < n) {
            ans.push_back({posn, n});
            ans.push_back({pos1, n});
        }
    } else {
        if (1 < posn) {
            ans.push_back({1, pos1});
            ans.push_back({1, posn});
        } 

        ans.push_back({posn, pos1});
        if (pos1 < n) {
            ans.push_back({pos1, n});
            ans.push_back({posn, n});
        }
    }

    cout << ans.size() << "\n";

    for (auto [l, r] : ans) {
        cout << l << " " << r << "\n";
    }

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}