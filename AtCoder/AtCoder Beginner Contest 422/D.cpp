#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    int elem = k / (1 << n);
    int res = k % (1 << n);

    vector<int> a(1 << n, elem);

    auto build = [&](auto &build, int i, int j, int cnt) {
        if (cnt == 0) return;
        if (i == j) {
            a[i]++;
            return;
        }

        int m = (i + j) >> 1;

        build(build, i, m, (cnt + 1) / 2);
        build(build, m+1, j, cnt / 2);
    };

    build(build, 0, (1 << n) - 1, res);
    int ans = 1;
    if (res == 0) ans = 0;
    cout << ans << endl;
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t; t = 1;
    while (t--) solve();
    
}