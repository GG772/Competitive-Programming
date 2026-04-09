#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;

    ll l = 1, r = n * n + 1;
    ll target = (n * n + 1) / 2;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        
        ll tot = 0;
        for (int i = 1; i <= n; i++) {
            tot += min(n, mid / i);
        }

        if (tot < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l << "\n";
}