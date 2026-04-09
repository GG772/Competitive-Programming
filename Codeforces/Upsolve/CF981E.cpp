#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), p(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) continue;
        else if (a[a[i]] == i) continue;

        int x = a[i], y = p[i];
        swap(a[x], a[y]);
        swap(p[a[x]], p[a[y]]);
        ans++;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}