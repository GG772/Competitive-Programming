#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<string> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<map<int, int>> mp(6);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string str = a[i];
        int sz = str.length();
        int SUM = 0;
        for (char c : str) SUM += (c - '0');
        mp[sz][SUM]++;
    }

    for (int i = 0; i < n; i++) {
        int start = 1;
        string str = a[i];
        int sz = str.length();
        if (sz % 2 == 0) start = 2;
        for (int j = start; j < 6; j += 2) {
            int s = 0, len = (j + sz) / 2;
            
            for (int k = 0; k < sz; k++) {
                if (k < len) {
                    s += (str[sz - 1 - k] - '0');
                } else {
                    s -= (str[sz - 1 - k] - '0');
                }
            }

            // cout << s << " ";
            ans += mp[j][s];

            s = 0;
            for (int k = 0; k < sz; k++) {
                if (k < len) {
                    s += (str[k] - '0');
                } else {
                    s -= (str[k] - '0');
                }
                k++;
            }
            ans += mp[j][s];
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; t = 1;
    while (t--) solve();
}