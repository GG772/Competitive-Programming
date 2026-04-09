#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    vector<int> pre(n+1), suf(n+1);
    for (int &x : a) {
        cin >> x;
    }

    for (int i = 0; i < n; i++) {
        pre[i+1] = (pre[i] + a[i]) % 3;
    }

    for (int i = n - 1; i > 0; i--) {
        suf[i - 1] = (suf[i] + a[i]) % 3;
    }

    for (int l = 1; l < n - 1; l++) {
        for (int r = l+1; r < n; r++) {
            
            int x = pre[l+1], y = suf[r], z = (pre[r+1] - pre[l+1] + 300) % 3;

            // if (l == 1 && r == 2) {
            //     cout << x << " " << y << " " << z << endl;
            // }

            if (x == y && x == z) {
                cout << l << " " << r << endl;
                return;
            } else if (x + y + z == 3) {
                cout << l << " " << r << endl;
                return;
            }
        }
    }

    cout << "0 0\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}