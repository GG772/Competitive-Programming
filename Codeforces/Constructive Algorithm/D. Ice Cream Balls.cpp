// Problem: https://codeforces.com/problemset/problem/1862/D

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n; cin >> n;

    ll lo = 0, hi = sqrtl(n);
    while (lo < hi) {
        ll mid = (hi - lo) / 2 + lo;
        if (mid * (mid + 1) < 2 * n) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << lo << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}