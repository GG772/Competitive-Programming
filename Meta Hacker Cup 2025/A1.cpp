#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, abs(a[i+1] - a[i]));
    }

    cout << "Case #" << t << ":" << ans << "\n";
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}