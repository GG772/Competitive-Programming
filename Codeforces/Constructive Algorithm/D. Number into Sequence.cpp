// Problem: https://codeforces.com/problemset/problem/1454/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n; cin >> n;
    ll cur = n;
    ll cc = 1;
    ll tmp = n;
    unordered_map<ll, int> cnt;
    
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            cnt[i]++;
        }
    }
    if (n > 1) {
        cnt[n]++;
    }

    for (auto p : cnt) {
        if (cc < p.second) {
            cur = p.first;
            cc = p.second;
        }
    }

    cout << cc << "\n";
    for (int i = 1; i < cc; i++) {
        cout << cur << " ";
        tmp /= cur;
    }
    cout << tmp << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
} 

