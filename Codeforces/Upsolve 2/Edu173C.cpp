#include <bits/stdc++.h>

using namespace std;
using ll = long long;

pair<int, int> helper(int start, int end, vector<int> &a) {
    int mx = 0, mn = 0;
    int mxp = 0, mnp = 0;

    int s = 0;
    for (int i = start; i < end; i++) {
        s += a[i];
        mx = max(mx, s - mnp);
        mn = min(mn, s - mxp);
        mxp = max(mxp, s);
        mnp = min(mnp, s);
    }
    return {mn, mx};
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int ptr = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1) ptr = i;
    }

    if (ptr == -1) {
        auto [mn, mx] = helper(0, n, a);
        cout << mx - mn + 1 << "\n";
        for (int i = mn; i <= mx; i++) {
            cout << i << " \n"[i == mx];
        }
    } else {
        auto [mn1, mx1] = helper(0, ptr, a);
        auto [mn2, mx2] = helper(ptr + 1, n, a);
        set<ll> ans;
        for (int i = mn1; i <= mx1; i++) {
            ans.insert(i);
        }

        for (int i = mn2; i <= mx2; i++) {
            ans.insert(i);
        }

        ll s = 0; 
        for (int j = ptr; j >= 0; j--) { 
            s += a[j]; ans.insert(s); 
        } 
        s = 0; 
        for (int j = ptr; j < n; j++) { 
            s += a[j]; ans.insert(s); 
        }
        
        vector<ll> pre(n+1), suf(ptr + 1);
        ll l_min = 0, l_max = 0;
        ll r_min = 0, r_max = 0;
        for (int i = ptr + 1; i < n; i++) {
            pre[i+1] = pre[i] + a[i];
            r_min = min(r_min, pre[i+1]);
            r_max = max(r_max, pre[i+1]);
        }

        for (int i = ptr - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + a[i];
            l_min = min(l_min, suf[i]);
            l_max = max(l_max, suf[i]);
        }

        for (int i = a[ptr] + l_min + r_min; i <= a[ptr] + l_max + r_max; i++) {
            ans.insert(i);
        }

        cout << ans.size() << "\n";

        for (ll x : ans) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}