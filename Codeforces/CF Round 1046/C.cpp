#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> cnt(n+1);
    vector<int> f(n+1);
    
    for (int i = 0; i < n; i++) {
        f[i+1] = f[i];
        cnt[a[i]].push_back(i);
        int end = cnt[a[i]].size();

        if (end >= a[i]) {
            int prev = cnt[a[i]][end - a[i]];
            f[i+1] = max(f[i+1], f[prev] + a[i]);
        }

    }

    cout << f[n] << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}