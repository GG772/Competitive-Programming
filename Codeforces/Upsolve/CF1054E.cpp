#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> solve(vector<int> a, int n, int k, bool f) {
    vector<int> ans(n);
    int r = 0;
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        while (r < n && cnt.size() < k) {
            cnt[a[r]]++;
            r++;
        }
        if (cnt.size() == k) ans[i] = r - 1;
        else ans[i] = n;
        cnt[a[i]]--;
        if (!cnt[a[i]]) cnt.erase(a[i]);
    }

    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k, l, r; cin >> n >> k >> l >> r;
        vector<int> a(n);

        for (int &x : a) cin >> x;
        vector<int> L = solve(a, n, k, true);
        vector<int> R = solve(a, n, k + 1, false);

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            if (L[i] == R[i]) continue;
            int l_len = L[i] - i + 1;
            int r_len = R[i] - i;

            if (r_len < l) continue;
            if (l_len > r) continue;

            l_len = max(l_len, l);
            r_len = min(r_len, r);
            
            ans += max(0, r_len - l_len + 1);
        }
        cout << ans << "\n";
    }
}