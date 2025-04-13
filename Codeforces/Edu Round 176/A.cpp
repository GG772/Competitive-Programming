#include <bits/stdc++.h>

using namespace std;

void solve() {
    

    int n, k; cin >> n >> k;

    int ans = 0;

    if (n % 2 == 1 && k % 2 == 1) {
        ans++;
        n -= k;
    }
    if (n == 0) {
        cout << ans << "\n";
        return;
    }
    

    ans += (n / (k-1));
    if (n % (k - 1) != 0) {
        ans++;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O
    int t; cin >> t;

    while (t--) {
        solve();
    }
}