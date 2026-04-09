// https://codeforces.com/problemset/problem/2193/C

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<i64> odd, even;

    for (int i = 0; i < n; i++) {
        i64 x; cin >> x;
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }

    if (odd.size() == 0) {
        cout << 0 << "\n";
        return;
    }

    sort(odd.begin(), odd.end());

    int l = 0, r = odd.size() - 1;
    i64 ans = 0;

    while (l <= r) {
        ans += odd[r];
        r--;
        l++;
    }

    for (int i = 0; i < even.size(); i++) {
        ans += even[i];
    }

    cout << ans << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}