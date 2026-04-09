// Problem: https://codeforces.com/problemset/problem/1446/A

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, w; cin >> n >> w;
    
    vector<ll> a(n);

    vector<pair<ll, int>> b;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if ((w + 1ll) / 2ll <= a[i] && a[i] <= w) {
            cout << 1 << "\n";
            cout << i + 1 << "\n";
            return;
        } else if (a[i] < (w + 1ll) / 2ll) {
            b.emplace_back(a[i], i + 1);
        }
    }

    ll s = 0;
    for (int i = 0; i < b.size(); i++) {
        ll elem = b[i].first;
        s += elem;
        if ((w + 1ll) / 2ll <= s && s <= w) {
            cout << i + 1 << "\n";
            for (int j = 0; j <= i; j++) {
                cout << b[j].second << " ";
            }
            cout << "\n";
            return;
        }
    }

    cout << -1 << "\n";
    
}

int main() {
    int t; cin >> t;
    int i = 1;
    while (t--) {
        cout << "tc: " << i << "\n";
        i++;
        solve();
    }
}