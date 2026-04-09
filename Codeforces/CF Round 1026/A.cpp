#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans1 = 0, ans2 = 0;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] % 2 == a[n-1] % 2) {
            break;
        }
        ans1++;
    }

    for (int i = n - 1; i > 0; i--) {
        if (a[i] % 2 == a[0] % 2) {
            break;
        }
        ans2++;
    }

    cout << min(ans1, ans2) << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}