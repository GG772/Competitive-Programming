// Problem: https://codeforces.com/contest/2078/problem/C


#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> b(2 * n);
        for (auto &x : b) cin >> x;

        sort(b.begin(), b.end());

        ll add = accumulate(b.begin(), b.begin() + n - 1, 0LL);
        ll sub = accumulate(b.begin() + n - 1, prev(b.end()), 0LL);

        ll rem = b.back() - (add - sub);

        cout << b.back() << ' ';
        b.insert(b.begin() + n - 1, rem);
        for (int i = 0; i < n; i++) {
            cout << b[i] << ' ' << b[i + n] << ' ';
        }
        cout << "\n";
    }
}