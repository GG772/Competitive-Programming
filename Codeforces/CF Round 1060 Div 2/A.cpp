#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int ans = 0;
    int sum = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (i - l + 1 > k) {
            sum -= s[l++] == '1';
        }
        if (s[i] == '1' && sum == 0) {
            ans++;
        }
        sum += s[i] == '1';
        
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}