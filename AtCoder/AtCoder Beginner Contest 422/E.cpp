#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

void solve() {
    mt19937 rng(time(0));
    int n; cin >> n;

    vector<pair<i64, i64>> p(n);

    for (auto &[x, y] : p) {
        cin >> x >> y;
    }

    auto check = [&](int i, int j) {
        if (i == j) return false;
        auto [x1, y1] = p[i];
        auto [x2, y2] = p[j];
        i64 a = y1 - y2;
        i64 b = x2 - x1;

        i64 c = -a * x1 - b * y1;
        int cnt = 0;
        for (auto [x, y] : p) {
            if (a * x + b * y + c == 0) {
                cnt++;
            }
        }

        if (cnt >= (n + 1) / 2) {
            cout << "Yes\n";
            cout << a << " " << b << " " << c << endl;
            return true;
        }
        return false;
    };

    int time = 100;
    for (int t = 0; t < time; t++) {
        int i = rng() % n, j = rng() % n;
        if (check(i, j)) return;
    }
    cout << "No\n";
}

int main() {
    int t; t = 1;
    while (t--) solve();
    
}