#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, int> cnt, cnt1, cnt2;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cnt[b[i]]++;
    }

    for (auto &[k, v] : cnt) {
        if (k != -1 && v > 1) {
            cout << "NO\n";
            return;
        }
    }

    if (n == k) {
        cout << "YES\n";
        return;
    }

    for (int i = 0; i < n - k; i++) {
        if (b[i] != -1 && a[i] != b[i]) {
            cout << "NO\n";
            return;
        }

        if (b[n-1-i] != -1 && a[n - 1 - i] != b[n - 1 - i]) {
            cout << "NO\n";
            return;
        }
    }

    for (int i = n - k; i < k; i++) {
        cnt1[a[i]]++;
        cnt2[b[i]]++;
    }

    int rem = 0;
    for (auto &[k, v] : cnt1) {
        rem += v - cnt2[k];
    }

    if (rem == cnt2[-1]) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }
}