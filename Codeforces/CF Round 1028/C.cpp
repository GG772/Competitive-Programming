#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int GCD = 0;    
    int ma = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        GCD = gcd(GCD, a[i]);
        ma = max(ma, a[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (a[i] == GCD);
    }

    if (cnt > 0) {
        cout << n - cnt << "\n";
        return;
    }

    // f(x) is the min op. needed to get x from the original array
    int inf = 1e9;
    vector<int> f(ma+1, inf);
    for (int i = 0; i < n; i++) {
        f[a[i]] = 0;
    }

    for (int x = ma; x > 0; x--) {
        for (int i = 0; i < n; i++) {
            f[gcd(x, a[i])] = min(f[x] + 1, f[gcd(x, a[i])]);
        }
    }

    cout << f[GCD] + (n - 1) << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}