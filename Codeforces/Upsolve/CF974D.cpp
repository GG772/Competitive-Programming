#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, d, k; cin >> n >> d >> k;

    vector<int> a(n + 2);

    for (int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        a[l]++, a[r+1]--;
    }

    vector<int> pre(n+2);

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i];
        // cout << pre[i] << " \n"[i == n]; 
    }

    int val1 = 0, val2 = INT_MAX / 2;
    int ans1 = 0, ans2 = 0;

    set<int> st;
    map<int, int> ind;
    int l = 1;
    for (int i = 1; i <= n - d; i++) {
        if (st.find(pre[i]) == st.end()) {
            st.insert(pre[i]);
            ind[pre[i]] = i;
        }

        int mx = *st.rbegin();
        int mn = *st.begin();

        if (mx > val1) {
            val1 = mx;
            ans1 = ind[mx];
        }

        if (mn < val2) {
            val2 = mn;
            ans2 = ind[mn];
        }

        if (i >= d) {
            auto it = st.find(pre[l]);
            if (it != st.end()) {
                st.erase(it);
            }
            ind.erase(pre[l]);
            l++;
        }
    }

    cout << ans1 << " " << ans2 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}