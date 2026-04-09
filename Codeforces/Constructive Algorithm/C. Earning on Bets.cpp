// Problem: https://codeforces.com/problemset/problem/1536/B

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int LCM = 1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        LCM = lcm(LCM, a[i]);
    }

    vector<int> ans(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        int term = LCM / a[i];
        s += (term);
        if (s >= LCM) {
            cout << -1 << "\n";
            return;
        }
        ans[i] = term;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }


}

int main() {
    int t; cin >> t;
    
    while (t--) {
        solve();
    }
}