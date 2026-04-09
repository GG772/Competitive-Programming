#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<bool> vis(n+1);

    if (n % 2) {
        cout << n << endl;
        int t = 0;
        for (int j = 0; j < 32; j++) {
            if ((n >> j) & 1) {
                t = j;
                break;
            }
        }

        int l1 = (1 << t);
        int l2 = l1 + (l1 == 1 ? 2 : 1);
        int r1 = n - l1, r2 = n;
        vis[l1] = true;
        vis[l2] = true;
        vis[r1] = true;
        vis[r2] = true;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cout << i << " ";
            }
        }
        cout << l1 << " " << l2 << " " << r1 << " " << r2 << "\n";
        return;
    }

    if (n & (n - 1)) {
        // n-1, n, h-1
        int hi = 0;
        for (int j = 31; j >= 0; j--) {
            if ((n >> j) & 1) {
                hi = j;
                break;
            }
        }

        cout << (1 << (hi + 1)) - 1 << "\n";

        int r = (1 << hi) - 1;
        for (int i = 1; i <= n; i++) {
            if (i != r) {
                cout << i << " ";
            }
        }

        cout << r << "\n";
        return;
    }
    // return;


    int t = -1;
    int hi = 0;
    for (int j = 0; j < 32; j++) {
        if ((((n - 1) >> j) & 1) && t == -1) {
            t = j;
            hi = j;
        } else if ((((n - 1) >> j) & 1)) {
            hi = j;
        }
    }

    int l1 = (1 << t);
    int l2 = l1 + (l1 == 1 ? 2 : 1);
    // cout << l1 << " " << l2 << "\n";
    int r1 = n - l1 - 1, r2 = n - 1;
    assert(r1 > -1);
    assert(r2 > -1);
    vis[l1] = true;
    vis[l2] = true;
    vis[r1] = true;
    vis[r2] = true;
    vis[n] = true;
    cout << (((1 << (hi + 1)) - 1) | n) << "\n";
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << i << " ";
        }
    }
    cout << l1 << " " << l2 << " " << r1 << " " << r2 << " " << n << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}