#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);

    sort(ans.begin(), ans.end(), [&](int i, int j) {
        return x[i] < x[j];
    });

    sort(ans.begin(), ans.begin() + n / 2, [&](int i, int j) {
        return y[i] < y[j];
    });

    sort(ans.begin() + n / 2, ans.end(), [&](int i, int j) {
        return y[i] < y[j];
    });

    for (int i = 0; i < n / 2; i++) {
        cout << ans[i] + 1 << " " << ans[n-1-i] + 1 << "\n";
    }
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}