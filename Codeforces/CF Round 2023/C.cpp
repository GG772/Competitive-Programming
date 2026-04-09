#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll maxSum(vector<ll> &a, int l, int r) {
    ll mi = 0;
    ll s = 0;
    ll ans = 0;
    for (int i = l; i < r; i++) {
        s += a[i];
        mi = min(mi, s);
        ans = max(ans, s - mi);
    }
    return ans;
}

void solve() {
    ll inf = 1e13;
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    vector<ll> a(n);
    vector<ll> pre(n+1);

    int pos = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i+1] = pre[i] + a[i];
        if (s[i] == '0') {
            a[i] = -inf;
            pos = i;
        }
    }

    ll res = maxSum(a, 0, n);
    if (res > k || (res < k && pos == -1)) {
        cout << "No\n";
        return;
    }

    ll s1 = 0, s2 = 0;
    ll tmp = 0;
    for (int i = pos - 1; i >= 0; i--) {
        tmp += a[i];
        s1 = max(s1, tmp);
    }

    for (int i = pos + 1; i < n; i++) {
        s2 = max(pre[i+1] - pre[pos], s2);
    }
    
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        if (i == pos) {
            cout << k - s1 - s2 << " ";
        } else {
            cout << a[i] << " ";
        }
    }

    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}