#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, a, b; cin >> n >> a >> b;

    string s; cin >> s;

    vector<int> pre(n+1);
    vector<int> pre2(n+1);

    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + (s[i] == 'b');
        pre2[i+1] = i + 1 - pre[i + 1];
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int l = lower_bound(pre2.begin() + i, pre2.end(), a + pre2[i]) - pre2.begin();
        int r = lower_bound(pre.begin() + i, pre.end(), b + pre[i]) - pre.begin() - 1;
        
        int hi = max(0, r - l + 1);
        ans += hi;
    }

    cout << ans << "\n";
}