#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    auto chk = [&](ll a, ll b, ll c) {
        ll l = 0, r = 600000001;
        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (a * mid * mid + b * mid + c < 0) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }   

        if (a * l * l + b * l + c == 0) return l;
        
        return -1ll;
    };

    for (ll d = 1; d * d * d <= n; d++) {
        if (n % d != 0) continue;
        ll c = d * d - n / d;
        ll b = 3ll * d;
        ll a = 3ll;
        
        // if (delta < 0) continue;

        ll res = chk(a, b, c);

        if (res > 0) {
            cout << res + d << " " << res << "\n";
            return 0;
        }

        // ll root1 = (-1ll * b + sqrtl(delta)) / (2ll * a);
        // ll root2 = (-1ll * b - sqrtl(delta)) / (2ll * a);
        
        // if (root1 > 0 && a * root1 * root1 + b * root1 == -c) {
        //     cout << root1 << " " << root1 + d << "\n";
        //     return 0;
        // }

        // if (root2 > 0 && a * root2 * root2 + b * root2 == -c) {
        //     cout << root2 << " " << root2 + d << "\n";
        //     return 0;
        // }
    }

    cout << -1 << "\n";

    // cout << 342756 - 66212 << " ";
}