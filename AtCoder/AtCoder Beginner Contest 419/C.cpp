#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    vector<pair<int, int>> g(n);
    int a = INT_MAX, b = 0, c = INT_MAX, d = 0;

    for (auto &[x, y] : g) {
        cin >> x >> y;
        a = min(a, x);
        b = max(b, x);
        c = min(c, y);
        d = max(d, y);
    }


    int x = (a + b + 1) / 2, y = (c + d + 1) / 2;

    int t = 0;
    for (auto &[xx, yy] : g) {
        int m1 = abs(x - xx), m2 = abs(y - yy);
        int mi = min(m1, m2);
        int tot = m1 + m2 - mi;
        t = max(t, tot);
    }

    cout << t << endl;
}