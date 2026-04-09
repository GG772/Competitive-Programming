#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), c(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> c[i];

    multiset<int> st(a.begin(), a.end());
    vector<tuple<int, int, int>> all(m);

    for (int i = 0; i < m; i++) {
        all[i] = {int(c[i] == 0), b[i], i};
    }

    sort(all.begin(), all.end());

    int ans = 0;
    for (auto &[_, __, i] : all) {
        auto it = st.lower_bound(b[i]);
        if (it != st.end()) {
            ans++;
            int val = *it;
            st.erase(it);
            if (c[i] > 0) {
                st.insert(max(val, c[i]));
            }
        }
    }

    cout << ans << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}