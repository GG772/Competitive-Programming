#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long;


int main () {
    int n, m; cin >> n >> m;

    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        ans += pow(n, i);
        if (ans > 1e9) {
            cout << "inf\n";
            return 0;
        }
    }

    if (ans <= 1e9) {
        cout << ans << "\n";
    } else {
        cout << "inf\n";
    }
}