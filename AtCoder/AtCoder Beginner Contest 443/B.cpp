#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, k; cin >> n >> k;

    int ans = 0;
    ll s = 0;
    while (s < k) {
        s += n++;
        ans++;
    }

    cout << ans - 1 << "\n";
}