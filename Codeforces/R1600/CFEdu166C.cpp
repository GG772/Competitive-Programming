#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n + m + 1), b(n + m + 1);

    for (int i = 0; i < n + m + 1; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n + m + 1; i++) {
        cin >> b[i];
    }

    int ptr1 = n + m, ptr2 = n + m, cnt1 = 0, cnt2 = 0;
    bool f1 = true, f2 = true;
    ll ans = 0;
    vector<bool> isA(n + m + 1);
    for (int i = 0; i < n + m; i++) {
        if (a[i] > b[i]) {
            cnt1++;
        } else {
            cnt2++;
        }

        if (cnt1 == n + 1 && f1) {
            ptr1 = i;
            f1 = false;
        }

        if (cnt2 == m + 1 && f2) {
            ptr2 = i;
            f2 = false;
        }
    }

    // cout << ptr1 << " " << ptr2 << "\n";

    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n + m; i++) {
        if (cnt1 == n) {
            ans += b[i];
            cnt2++;
        } else if (cnt2 == m) {
            ans += a[i];
            cnt1++;
            isA[i] = true;
        } else {
            if (a[i] > b[i]) {
                ans += a[i];
                cnt1++;
                isA[i] = true;
            } else {
                ans += b[i];
                cnt2++;
            }
        }
    }

    for (int i = 0; i < n + m + 1; i++) {
        if (i == n + m) {
            cout << ans << "\n";
        } else if (isA[i]) {
            ll res = ans - a[i] + a[ptr1];
            if (ptr1 < n + m) {
                res = res - b[ptr1] + b.back();
            }
            cout << res << " ";
        } else {
            ll res = ans - b[i] + b[ptr2];
            if (ptr2 < n + m) {
                res = res - a[ptr2] + a.back();
            }
            cout << res << " ";
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}