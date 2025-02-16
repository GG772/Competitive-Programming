#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> mx(n + 1);
    vector<long long> mn(n + 1);
    // mx[i] / mn[i] == max and min strength of a team chosen from a[i], a[i+1], ..., a[n-1]
    // alternating sign, maximizing a - b is equavalent of minimizing b, given a
    // in this case, a is mx, b is mn

    for (int i = n - 1; i >= 0; i--) {
        mx[i] = max(mx[i+1], a[i] - mn[i+1]);
        mn[i] = min(mn[i+1], a[i] - mx[i+1]);
    }

    cout << mx[0] << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}