#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    int n = s.length();
    int ans = (s[0] == 'u') + (s.back() == 'u');

    s[0] = 's';
    s[n-1] = 's';

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i+1] && s[i+1] == 'u') {
            ans++;
            s[i+1] = 's';
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}