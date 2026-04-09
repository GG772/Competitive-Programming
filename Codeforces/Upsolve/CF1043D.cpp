#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void solve() {
    ll k; cin >> k;
    
    auto search1 = [&] (ll x) -> pair<ll, ll> {
        if (x < 10) return {x, 0};
        ll base = 1;
        int len = 1;
        ll s = k, cnt = 1;
        while (s - 9 * base * cnt >= 0) {
            s -= 9 * base * cnt;
            base *= 10;
            cnt++;
            len++;
        }
        ll last = (s + len - 1) / len + (base - 1);

        ll rem = s % len;
        // cout << last << " " << rem << "\n";
        
        return {last, rem};
    };
    auto [last, rem] = search1(k);

    vector<int> digits;
    ll tmp = last - 1, cur = last - 1;
    if (rem == 0) {
        tmp++, cur++;
    }
    while (tmp > 0) {
        digits.push_back(tmp % 10);
        tmp /= 10;
    }

    reverse(digits.begin(), digits.end());
    int m = digits.size();

    vector<ll> pow(17, 1);

    for (int i = 1; i <= 16; i++) {
        pow[i] = 10 * pow[i-1];
    }

    ll ans = 0;

    for (ll p = 1; p <= cur; p *= 10) {
        ll hi = cur / (10 * p);
        ll mid = (cur / p) % 10;
        ll lo = cur % p;
        ans += hi * p * 45;
        ans += mid * (mid - 1) / 2 * p;
        ans += mid * (lo + 1);
    }
    string s = to_string(last);
    for (int i = 0; i < rem; i++) {
        ans += s[i] - '0';
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}