#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string s; cin >> s;
    int n = s.length();

    auto calc = [&](int x) -> ll {
        ll ans = 0;
        char c = char(x + '0');
        char c2 = char((x + 1) + '0');
        int l = 0;
        while (l < n) {
            if (s[l] != c) {
                l++;
                continue;
            }

            ll cnt1 = 1, cnt2 = 0;
            int r = l + 1;
            while (r < n && s[r] == c) {
                cnt1++;
                r++;
            }
            while (r < n && s[r] == c2) {
                cnt2++;
                r++;
            }
            ans += min(cnt1, cnt2);
            l = r;
        }

        return ans;
    };

    ll res = 0;
    for (int i = 0; i <= 8; i++) {
        res += calc(i);
    }

    cout << res << "\n";
    
    
}