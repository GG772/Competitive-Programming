#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(m);

    int cnt = (n + k - 1) / k;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    
    int c = 0;
    for (int x : a) {
        if (x > cnt) {
            cout << "No\n";
            return;
        }
        c += (x == cnt);
    }

    if (c > (n - 1 + k) % k + 1) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}