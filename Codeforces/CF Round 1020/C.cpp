#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int mn = INT_MAX, mx = 0;

    int s = -1;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        mn = min(a[i], mn);
        mx = max(a[i], mx);

        if (b[i] > -1) {
            cnt++;
            if (s == -1) {
                s = a[i] + b[i];
                continue;
            } else {
                if (a[i] + b[i] != s) {
                    cout << "0\n";
                    return;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if ((s > -1) && (s - a[i] > k || a[i] > s)) {
            cout << "0\n";
            return;
        }
    }

    if (cnt) {
        cout << "1\n";
    } else {
        cout << k - (mx - mn) + 1 << "\n";
    } 

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}