#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> ans(n + 1);

    iota(ans.begin() + 1, ans.end(), 1);
    ans[r] = ans[l-1];

    for (int i = 1; i <= n; i++) {
        int cur = ans[i] ^ ans[i-1];
        cout << cur << " \n"[i == n];
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}