#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    string s; cin >> s;

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        cnt0 += (s[i] == '0');
        cnt1 += (s[i] == '1');
    }

    for (int l = 0; l <= k; l++) {
        int rem1 = cnt0 - 2 * l;
        int rem2 = cnt1 - 2 * (k - l);
        if (rem1 >= 0 && rem2 >= 0 && rem1 == rem2) {
            cout << "yes\n";
            return;
        }
    }

    cout << "no\n";

    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}