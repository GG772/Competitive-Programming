#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    int s = 0;
    for (int i = 0; i < n - 1; i++) {
        s += abs(a[i+1] - a[i]);
    }

    int ans = s;
    for (int i = 1; i < n - 1; i++) {
        int ss = s - abs(a[i] - a[i-1]) - abs(a[i + 1] - a[i]) + abs(a[i+1] - a[i - 1]);
        ans = min(ans, ss);
    }

    ans = min(ans, s - abs(a[1] - a[0]));
    ans = min(ans, s - abs(a[n-1] - a[n-2]));
    cout << ans << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}