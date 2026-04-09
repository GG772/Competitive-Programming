#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int mx = INT_MIN, mn = INT_MAX;
    for (int &x : a) {
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
    }

    int ans = 0;
    bool f1 = false;
    vector<int> op;
    while (mx > mn) {
        int b = mn % 2;
        op.push_back(b);
        mn = (mn + b) >> 1;
        mx = (mx + b) >> 1;
        ans++;
    }

    cout << ans << "\n";
    if (ans <= n) {
        if (ans == 0) return;
        for (int i = 0; i < ans; i++) {
            cout << op[i] << " \n"[i == ans - 1];
        }

    }
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}