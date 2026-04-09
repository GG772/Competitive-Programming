#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    vector<int> b(n);

    for (int i = 1; i < n; i++) {
        b[i] = gcd(a[i-1], a[i]);
    }
    b[0] = INT_MIN / 2;

    vector<bool> pre(n), suf(n);

    pre[0] = true;
    suf[n-1] = true;
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] && b[i] >= b[i-1];
    }

    for (int i = n - 2; i >= 0; i--) {
        int cand = INT_MAX;
        if (i + 2 < n) cand = b[i+2]; 
        suf[i] = suf[i+1] && b[i+2] >= b[i+1]; 
    }

    auto chk = [&](int i) -> bool {
        if (i > 0 && i < n) {
            int g = gcd(a[i-1], a[i+1]);
            bool f = true;
            if (i + 1 < n) f = suf[i+1];
            bool f2 = true;
            if (i + 2 < n) f2 = g <= b[i+2];
            bool result = pre[i] && f2 && f;
            return result;
        } else if (i == 0) {
            return suf[1];
        } else {
            return pre[n-1];
        }
    };

    for (int i = 0; i < n; i++) {
        if (chk(i)) {
            cout << pre[3] << " ";
            cout << i << " ";
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}