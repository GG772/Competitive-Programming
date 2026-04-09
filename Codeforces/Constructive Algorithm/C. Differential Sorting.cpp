// Problem: https://codeforces.com/problemset/problem/1635/C

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a[n-2] > a[n-1]) {
        cout << -1 << "\n";
        return;
    }

    vector<tuple<int, int, int>> ans;
    for (int i = n - 3; i >= 0; i--) {
        if (a[i] <= a[i+1]) {
            continue;
        }

        ll diff = a[i+1] - a[n-1];

        if (diff <= a[i+1]) {
            ans.push_back(make_tuple(i, i+1, n-1));
            a[i] = diff;
        } else {
            cout << -1 << "\n";
            return;
        }
    }

    cout << ans.size() << "\n";

    for (auto &t : ans) {
        int x = get<0>(t) + 1;
        int y = get<1>(t) + 1;
        int z = get<2>(t) + 1;
        cout << x << " " << y << " " << z << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}