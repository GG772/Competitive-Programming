#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> c(n), p(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i] >> p[i];
    }

    double ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans = max(ans, c[i] + ans * (1 - (double) p[i] / 100.0));
    }

    cout << setprecision(10) << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}