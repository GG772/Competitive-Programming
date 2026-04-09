#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1e14;

int main() {
    int n; cin >> n;
    map<ll, int> mp;
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        mp[a]++;
        mp[b]--;
    }

    ll ans = 0, s = 0, last = -inf;
    for (auto [i, v] : mp) {
        s += v;
        if (s > 0 && last == -inf) {
            last = i;
        } else if (s == 0 && last != -inf) {
            ans += i - last;
            last = -inf;
        }
    }

    cout << ans << "\n";
}