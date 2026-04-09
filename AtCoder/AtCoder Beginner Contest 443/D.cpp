#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll inf = 1e10;

    vector<ll> L(n + 1, inf), R(n+1, inf);

    for (int i = 0; i < n; i++) {
        L[i + 1] = min(L[i], a[i] - 1) + 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        R[i] = min(R[i+1], a[i] - 1) + 1;
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a[i] - min(L[i+1], R[i]));
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}