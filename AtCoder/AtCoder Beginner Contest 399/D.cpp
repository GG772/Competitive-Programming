#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n + 1);

    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }

    map<pair<int, int>, int> cnt;

    int res = 0;
    for (int i = 1; i < 2 * n; i++) {
        int cur = a[i], nxt = a[i+1];
        
        if (cnt[{cur, nxt}]) {
            res++;
        }

        if (cnt[{nxt, cur}] && i - cnt[{nxt, cur}] > 2) {
            res++;
        }
        cnt[{cur, nxt}] = i;
    }

    cout << res << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}