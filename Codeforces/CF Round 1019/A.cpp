#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> cnt(n+1);
    int ans = n;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        cnt[tmp]++;
        if (cnt[tmp] > 1) {
            ans--;
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