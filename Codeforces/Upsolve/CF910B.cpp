#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    ll ans = 0;
    int mn = a.back();
    for (int i = n - 2; i >= 0; i--) {
        int k = (a[i] + mn - 1) / mn;
        ans += k - 1;
        mn = a[i] / k;
    }   

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}