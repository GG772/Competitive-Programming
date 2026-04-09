#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int t) {
    int n; cin >> n;
    vector<ll> a(n);

    ll mx = 0;
    for (ll &x : a) {
        cin >> x;
        mx = max(mx, x);
    }
    ll ans = 0;

    auto check = [&](ll mid) -> bool {
        queue<int> q;
        vector<int> vis(n);
        for (int i = 0; i < n; i++) {
            if (a[i] <= mid) {
                q.push(i);
                vis[i] = 1;
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (i > 0 && !vis[i-1] && abs(a[i-1] - a[i]) <= mid) {
                q.push(i-1);
                vis[i-1] = 1;
            }
            if (i < n - 1 && !vis[i+1] && abs(a[i+1] - a[i]) <= mid) {
                q.push(i+1);
                vis[i+1] = 1;
            } 
        }
        
        return accumulate(vis.begin(), vis.end(), 0) == n;
    };

    ll l = 1, r = mx + 1;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << "Case #" << t << ": " << l << "\n";
    // cout << check(1) << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}