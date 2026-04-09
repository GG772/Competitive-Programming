#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);

    int tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
    }

    if (tot % 2) {
        cout << "-1\n";
        return;
    }

    vector<pair<int, int>> ps, ans, tmp;
    
    int last = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 0 && last == -1) {
            last = i;
        } else if (a[i] != 0) {
            ps.push_back({last, i});
            last = -1;
        }
    }

    for (auto [l, r] : ps) {
        if (a[l] == a[r]) {
            if ((l % 2) != (r % 2)) {
                tmp.push_back({l, r});
            } else {
                tmp.push_back({l, r - 2});
                tmp.push_back({r - 1, r});
            }
        } else {
            if ((l % 2) == (r % 2)) {
                tmp.push_back({l, r});
            } else {
                tmp.push_back({l, r - 1});
                tmp.push_back({r, r});
            }
        }
    }

    if (!tmp.empty() && tmp[0].first != 1) {
        ans.push_back({1, tmp[0].first - 1});
    }

    for (auto [l, r] : tmp) {
        int last_l = n + 1;
        if (!ans.empty()) {
            last_l = ans.back().second;
        }
        if (last_l + 1 < l) {
            ans.push_back({last_l + 1, l - 1});
        }
        ans.push_back({l, r});
    }

    if (!tmp.empty() && tmp.back().second != n) {
        ans.push_back({tmp.back().second + 1, n});
    }

    if (ans.empty()) {
        cout << 1 << "\n";
        cout << 1 << " " << n << "\n";
        return;
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}