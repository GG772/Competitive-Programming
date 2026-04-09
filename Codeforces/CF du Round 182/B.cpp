#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int mn = 1, mx = n; 
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) mp[a[i]] = 1;
        while (mp.count(mn)) {
            mn++;
        }

        while (mp.count(mx)) {
            mx--;
        }
    }

    int l = 0, r = n - 1;
    while (l < n && a[l] != 0) l++;
    while (r >= 0 && a[r] != 0) r--;

    cout << l << " " << r << endl;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            ans = max(ans, abs(i + 1 - a[i]));
        } 
    }
    
    ans = max({ans, abs(mx - l - 1), abs(mx - r - 1), abs(mn - l - 1), abs(mn - r - 1)});

    cout << ans << endl;


}

int main() {
    int t; cin >> t;
    while (t--) solve();
}