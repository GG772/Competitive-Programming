// Problem: https://codeforces.com/contest/2085/problem/D

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    priority_queue<int> pq;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        pq.push(a[i]);
        if ((n - i) % (k + 1) == 0) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O
    int t; cin >> t;
    while (t--) {
        solve();
    }
}