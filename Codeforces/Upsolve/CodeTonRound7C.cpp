#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = make_pair(x, i);
    }
    for (int &x : b) cin >> x;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<int> na(n), nb(n);

    int l = n - k, r = 0, cnt = 0;
    
    while (cnt < k) {
        if (a[l].first > b[r]) {
            cnt++;
            int j = a[l].second;
            na[j] = a[l].first;
            nb[j] = b[r];
            l++, r++;
        } else {
            break;
        }
    }

    if (cnt < k) {
        cout << "NO\n";
        return;
    }

    int new_l = 0;

    while (new_l <= n - k - 1 && r < n) {
        int j = a[new_l].second;
        na[j] = a[new_l].first;
        nb[j] = b[r];
        new_l++, r++;
    }

    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
        cnt2 += (na[i] > nb[i]);
    }

    if (cnt2 != k) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << nb[i] << " \n"[i == n-1];
    }
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}