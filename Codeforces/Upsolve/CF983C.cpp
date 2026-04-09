#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int inf = 1e9 + 7;
void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    int ans = inf;

    for (int i = 0; i < n - 1; i++) {
        int cnt = n - (lower_bound(a.begin(), a.end(), a[i] + a[i+1]) - a.begin());
        ans = min(ans, cnt + i);
    }


    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}