// Problem: https://codeforces.com/contest/2084/problem/B

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // if (a[0] == a[1]) {
    //     cout << "Yes\n";
    //     return;
    // }

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] % a[0] == 0) {
            ans = std::gcd(ans, a[i]);
        }
    }

    if (ans == a[0]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }


}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}