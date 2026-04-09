#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int cnt1 = 0, cnt2 = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) cnt1++;
            else if (a[i] > a[j]) cnt2++;
        }
        cout << max(cnt1, cnt2) << " \n"[i == n-1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}