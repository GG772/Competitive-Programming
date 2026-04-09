#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);

    vector<int> pre0(n + 1), pre1(n + 1);

    set<int> st;

    for (int &x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        pre0[i+1] = pre0[i] + (a[i] == 0);
        pre1[i+1] = pre1[i] + (a[i] == 1);
        if (i > 0 && a[i] == a[i-1]) {
            st.insert(i);
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        if ((pre0[r] - pre0[l-1]) % 3 != 0) {
            cout << -1 << "\n";
            continue;
        } else if ((pre1[r] - pre1[l-1]) % 3 != 0) {
            cout << -1 << "\n";
            continue;
        }

        int c1 = (pre0[r] - pre0[l-1]), c2 = (pre1[r] - pre1[l-1]);
        if (c1 != c2) {
            cout << (r - l + 1) / 3 << "\n";
        } else {
            auto it = st.upper_bound(l);
            if (it != st.end() && *it <= r - 1) {
                cout << (r - l + 1) / 3 << "\n";
            } else {
                cout << 2 + (r - l - 2) / 3 << "\n";
            }
        }
    }
    
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}