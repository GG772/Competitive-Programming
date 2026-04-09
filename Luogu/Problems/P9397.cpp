#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<tuple<int, int, int>> a(n);

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = {x, y, i};
    }

    if (n % 2 == 1) {
        cout << -1 << "\n";
        return 0;
    }

    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 1; i < n; i += 2) {
        auto [x1, y1, j] = a[i-1];
        auto [x2, y2, k] = a[i];
        ans += (x2 - x1);
    }

    cout << ans << "\n";
    for (int i = 1; i < n; i += 2) {
        auto [x1, y1, j] = a[i-1];
        auto [x2, y2, k] = a[i];
        cout << j + 1 << " " << k + 1 << "\n";
    }
    
}