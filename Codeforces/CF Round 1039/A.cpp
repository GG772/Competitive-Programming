#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, c; cin >> n >> c;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int s = 0;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll prod = (1ll << s);
        if (a[i] * prod <= 1ll * c) {
            cnt++;
            s++;
        }
    }
    
    cout << n - cnt << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}