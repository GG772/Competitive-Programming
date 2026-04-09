#include <bits/stdc++.h>

using namespace std;
const int inf = 2e6;

void solve() {
    int n; cin >> n;
    vector<int> p(n);

    for (int &x : p) cin >> x;

    vector<int> pre(n+1, inf), suf(n+1);
    for (int i = 0; i < n; i++) {
        pre[i+1] = min(pre[i], p[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = max(suf[i+1], p[i]);
    }

    vector<int> indices;
    for (int i = 1; i < n; i++) {
        if (pre[i] > suf[i]) {
            cout << "No\n";
            return;
        }
        if (p[i] == suf[i]) indices.push_back(i);
    }

    int l = 0, m = indices.size();
    set<pair<int, int>> st;
    vector<pair<int, int>> groups;
    cout << "Yes\n";

    for (int i = 0; i < m; i++) {
        int r = indices[i];
        int mn = p[r], mx = p[r];
        while (l < r) {
            cout << p[l] << " " << p[r] << "\n";
            st.insert(make_pair(p[l], p[r]));
            mn = min(mn, p[l]);
            mx = max(mx, p[r]);
            l++;
        }
        groups.push_back({mn, mx});
        l++;
    }

    m = groups.size();
    int mn = inf;
    for (int i = 0; i < m - 1; i++) {
        mn = min(mn, groups[i].first);
        bool f = !st.count({mn, groups[i+1].second}) && !st.count({groups[i+1].second, mn});
        if (f) cout << mn << " " << groups[i+1].second << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}