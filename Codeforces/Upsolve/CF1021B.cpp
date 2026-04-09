#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());

    int l = (1 + n - k) / 2;
    int r = (k + 1 + n + 1) / 2;

    cout << a[r] - a[l] + 1 << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}