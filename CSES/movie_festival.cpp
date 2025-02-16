
#include <bits/stdc++.h>

using namespace std;

 
int main() {
    int n; cin >> n;

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p.emplace_back(y, x);
    }

    sort(p.begin(), p.end());

    int mx = 0, ans = 0;
    for (auto [y, x] : p) {
        if (mx <= x) {
            ans++;
            mx = max(mx, y);
        }
    }

    cout << ans << '\n';
    return 0;
}