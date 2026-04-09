#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    multiset<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        st.insert({deg[i], i});
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        st.erase(st.find({deg[i], i}));

        for (int nxt : g[i]) {
            st.erase(st.find({deg[nxt], nxt}));
            st.insert({deg[nxt] - 1, nxt});
        }
        auto [candidate_deg, candidate] = *st.rbegin();

        ans = max(ans, candidate_deg + deg[i] - 1);

        for (int nxt : g[i]) {
            st.erase(st.find({deg[nxt] - 1, nxt}));
            st.insert({deg[nxt], nxt});
        }
        st.insert({deg[i], i});
    }

    cout << ans << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}