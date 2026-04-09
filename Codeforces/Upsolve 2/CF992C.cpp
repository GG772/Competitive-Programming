#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    ll k; cin >> k;
    k--;
    
    if (n <= 60 && k >= (1ll << (n - 1))) {
        cout << -1 << "\n";
        return;
    }

    vector<int> p(n);
    int l = 0, r = n - 1;
    for (int i = 1; i < n; i++) {
        if (n - i - 1 > 60 || k < (1ll << (n - i - 1))) {
            p[l++] = i;
        } else {
            p[r--] = i;
            k -= (1ll << (n - i - 1));
        }
    }

    p[l] = n;

    for (int i = 0; i < n; i++) cout << p[i] << " \n"[i == n-1];
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
