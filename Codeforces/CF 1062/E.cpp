#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> a;

    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a.push_back(t);
    }

    sort(a.begin(), a.end());

    auto chk = [&](int val) -> bool {
        int cnt = 0;
        bool ok = false;
        cnt += max(0, a[0] - val + 1);
        cnt += max(0, x - a[n-1] - val + 1);        
        for (int i = 1; i < n; i++) {
            cnt += max(0, a[i] - a[i-1] - 2 * val + 1);
        }
        return cnt >= k;
    };

    int l = 0, r = 1e9 + 1;
    while (l < r) {
        int mid = (l + r) >> 1;

        if (chk(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    if (l - 1 == 0) {
        for (int i = 0; i < k; i++) {
            cout << i << " \n"[i == k-1];
        }
        return;
    }

    bool ok = false;
    int val = l - 1;
    for (int i = 0; i <= a[0] - val; i++) {
        if (k > 0) {
            cout << i << " ";
            k--;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = a[i-1] + val; j <= a[i] - val; j++) {
            if (k > 0) {
                cout << j << " ";
                k--;
            }
        }  
    }

    for (int i = a[n-1] + val; i <= x; i++) {
        if (k > 0) {
            cout << i << " ";
            k--;
        }
    }
    
    cout << "\n";
}

int main() {
    int t; cin >> t;
    
    while (t--) solve();
    
}