// Problem: https://codeforces.com/problemset/problem/1775/B

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
vector<int> p[N];

void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);

    map<int, int> l, r;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        r[b[i]] = i;
    }

    int ans = 1;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int d = (l[i] - r[i] + n) % n;
        mp[d]++;
        ans = max(ans, mp[d]);
    }

    
    cout << ans << endl;
    
}
int main() {
    // int t; cin >> t;
    int t = 1;
    while (t--) {
        solve();
    }
}