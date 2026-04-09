#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<int> a(k);

    for (int &x : a) {
        cin >> x;
    }

    auto chk = [&](int n, int m) -> bool {
        ll tot = 0;
        vector<int> b(k);
        for (int i = 0; i < k; i++) {
            b[i] = a[i] / m;
            if (b[i] == 1) {
                b[i] = 0;
            }

            tot += b[i];
        }

        if (tot < n) return false;
        if (n % 2 == 1 && count(b.begin(), b.end(), 0) + count(b.begin(), b.end(), 2) == k) return false;
        return true;
    };

    if (chk(n, m) || chk(m, n)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}