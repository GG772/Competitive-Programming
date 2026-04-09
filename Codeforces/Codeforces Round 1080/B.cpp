#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<bool> vis(n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j *= 2) {
            vis[a[j]] = true;
        }   

        for (int j = i; j <= n; j *= 2) {
            if (!vis[j]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}