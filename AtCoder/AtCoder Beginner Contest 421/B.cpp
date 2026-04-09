#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll f(ll x, ll y) {
    string s = to_string(x + y);
    
    reverse(s.begin(), s.end());
    // cout << s << endl;
    ll ans = 0;
    bool f1 = true;
    for (int i = 0; i < s.length(); i++) {
        if (f1 && (s[i] - '0') == 0) {
            continue;
        } else {
            f1 = false;
            ans = ans * 10 + (s[i] - '0');
        }
    }

    return ans;
}

int main() {
    ll x, y; cin >> x >> y;

    vector<ll> a(11);
    a[1] = x, a[2] = y;
    for (int i = 3; i < 11; i++) {
        a[i] = f(a[i-1], a[i-2]);
        // cout << a[i] << endl;
    }

    cout << a[10] << endl;
}