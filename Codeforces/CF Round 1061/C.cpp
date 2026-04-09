#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> cnt(n + 1);
    vector<int> a(n);

    vector<ll> pre(n+1);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
        a[i] = x;
    }

    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + cnt[i+1];
    }

    sort(a.begin(), a.end());

    int ans = 1;
    for (int i = n; i >= 1; i--) {
        // if cnt of < 4 * d elements not divisible by d is less than or equal to k
        // then this is our answer
        int good = 0;
        if (4 * i - 1 <= n) {
            good += (pre[n] - pre[4 * i - 1]);
        }
        if (3 * i <= n) {
            good += cnt[3 * i];
        } 
        if (2 * i <= n) {
            good += cnt[2 * i];
        }

        good += cnt[i];
        
        if (good >= n - k) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}