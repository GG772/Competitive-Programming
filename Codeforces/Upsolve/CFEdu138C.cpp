#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int inf = 1e9 + 7;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());
    int ans = 0;
    auto chk = [&](int val) -> bool {
        if (n == 1) return true;
        vector<int> b = a;
        int r = n - 1;
        int l = 0;
        while (r >= 0 && b[r] > val) r--;
        int cnt = 0, t = val;
        while (cnt < val) {
            while (r >= 0 && b[r] > t) r--;
            if (r < 0) return false;

            b[r] += n + 1;
            b[l++] += n + 1;
            r--;
            t--;
            cnt++;
        }

        return true;
    };

    for (int i = n; i >= 1; i--) {
        if (chk(i)) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}