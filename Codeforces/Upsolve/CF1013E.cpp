#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int sz = 1e7 + 1;
int a[sz];
void solve() {
    int n; cin >> n;

    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        if (!a[i]) {
            ans += n / i;
        }
    }

    cout << ans << "\n";

}

int main() {
    for (int i = 2; i <= 1e7; i++) {
        if (a[i] != 1) {
            for (int cnt = 2; cnt * i <= 1e7; cnt++) {
                a[i * cnt] = 1;
            }
        }
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
}