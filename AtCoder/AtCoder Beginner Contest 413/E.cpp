// idea: divide and conquer

#include <bits/stdc++.h>

using namespace std;
vector<int> a;

void solve() {
    int n; cin >> n;

    vector<int> a(1 << n);

    for (int &x : a) cin >> x;

    auto dfs = [&](auto &dfs, int l, int r) -> pair<int, vector<int>> {
        if (l == r) {
            vector<int> ans;
            ans.push_back(a[l]);
            return make_pair(a[l], ans);
        }
        int m = (l + r) >> 1;
        auto [l_min, lv] = dfs(dfs, l, m);
        auto [r_min, rv] = dfs(dfs, m + 1, r);
        if (l_min < r_min) {
            for (int x : rv) {
                lv.push_back(x);
            }
            rv.clear();
            return make_pair(l_min, lv);
        } else {
            for (int x : lv) {
                rv.push_back(x);
            }
            lv.clear();
            return make_pair(r_min, rv);
        }
    };

    auto [_, v] = dfs(dfs, 0, (1 << n) - 1);

    for (int x : v) cout << x << " ";
    cout << endl;

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}