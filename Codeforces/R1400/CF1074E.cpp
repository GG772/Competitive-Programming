#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int m = 1e9 + 7;

void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n);
    vector<array<int, 3>> pre(k+1);
    set<int> st;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        st.insert(x);
    }

    string s; cin >> s;
    for (int i = 0; i < k; i++) {
        auto [mn, mx, offset] = pre[i];
        if (s[i] == 'L') {
            pre[i+1] = {min(mn, offset - 1), max(mx, offset - 1), offset - 1};
        } else {
            pre[i+1] = {min(mn, offset + 1), max(mx, offset + 1), offset + 1};
        }
    }

    vector<int> ans(k + 2);

    for (int i = 0; i < n; i++) {
        int l = 1, r = k + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            auto [mn, mx, _] = pre[mid];
            auto it = st.upper_bound(a[i]);
            int left = -1, right = -1;
            if (it != st.end()) {
                right = *it;
            }

            if (it != st.begin()) {
                left = *prev(it);
            }
            
            bool f = false;
            if (left != -1 && left >= a[i] - abs(mn)) {
                f = true;
            }

            if (right != -1 && right <= a[i] + mx) {
                f = true;
            }

            if (f) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans[l] -= 1;
    }

    int cur = n;
    for (int i = 1; i <= k; i++) {
        cur += ans[i];
        cout << cur << " \n"[i == k];
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    
}