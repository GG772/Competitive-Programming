#include <bits/stdc++.h>

using namespace std; 
using ll = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);

    for (int &x : a) cin >> x;
    
    vector<int> pre(n+1);
    vector<ll> pre2(n+1);

    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + (a[i] == 1);
        pre2[i+1] = pre2[i] + a[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        if (l == r) {
            cout << "No\n";
            continue;
        }
        
        ll cnt = -(r - l + 1);
        l--;
        cnt += pre2[r] - pre2[l];
        ll cnt2 = pre[r] - pre[l];

        // cout << cnt << " " << cnt2 << " ";
        if (cnt < cnt2) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}