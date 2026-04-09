#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll a, b, n; cin >> a >> b >> n;

    string ans = to_string(a);
    bool f = true;
    for (int i = 0; i <= 9; i++) {
        if ((a * 10 + i) % b == 0) {
            ans += to_string(i);
            f = false;
            n--;
            break;
        }
    }

    if (f) cout << -1 << "\n";
    else {
        ans += string(n, '0');
        cout << ans << "\n";
    }
}