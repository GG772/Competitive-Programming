#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= k) {
            a[i] = 1;
        } else {
            a[i] = -1;
        }
    }

    // 3 cases
    // first case: greatest segment in the middle
    int l = 1, cur = a[0];
    while (l < n && cur < 0) cur += a[l++];
    int r = n - 2;
    cur = a[n-1];
    while (r > 0 && cur < 0) cur += a[r--];

    if (l <= r) {
        cout << "Yes\n";
        return;
    }
    
    auto check = [&](vector<int> &b) -> bool {
        int cur = 0;
        set<int> s;
        for (int i = 0; i < n - 1; i++) {
            cur += b[i];
            if (cur < 0) continue;
            if (cur > 1) return true;
            if (cur == 0 && s.find(0) != s.end()) return true;
            if (cur && s.size() > 0) return true;
            s.insert(cur);
        }

        return false;
    };
    auto b = a;
    ranges::reverse(b);
    if (check(a) || check(b)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }
}