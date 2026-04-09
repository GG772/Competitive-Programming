#include <bits/stdc++.h>

using namespace std;

const int inf = 1e7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> pre(n+1, inf), suf(n+1);

    for (int i = 0; i < n; i++) {
        pre[i+1] = min(pre[i], a[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = max(suf[i+1], a[i]);
    }

    for (int i = 1; i < n; i++) {
        if (pre[i] > suf[i+1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";


}

int main() {
    int t; cin >> t;
    while (t--) solve();
}