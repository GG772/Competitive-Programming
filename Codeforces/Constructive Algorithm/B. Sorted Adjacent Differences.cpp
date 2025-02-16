#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    vector<int> ans;
    
    for (int i = 0; i < n / 2; i++) {
        ans.push_back(a[i]);
        ans.push_back(a[n-1-i]);
    }

    if (n % 2 == 1) {
        ans.push_back(a[(n-1)/2]);
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}