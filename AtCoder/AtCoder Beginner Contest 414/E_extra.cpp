// https://www.luogu.com.cn/problem/UVA11526?lang=en


#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n; cin >> n;
    ll ans = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);

        ans += (r - l + 1) * (n / l);
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}