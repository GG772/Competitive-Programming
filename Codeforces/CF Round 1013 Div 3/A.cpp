// Problem: https://codeforces.com/contest/2091/problem/A

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt5 = 0;

    int n; cin >> n;
    int ans = 0;
    bool status = true;
    for (int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        if (tmp == 0) cnt0++;
        if (tmp == 1) cnt1++;
        if (tmp == 2) cnt2++;
        if (tmp == 3) cnt3++;
        if (tmp == 5) cnt5++;
        if (cnt0 >= 3 && cnt1 >= 1 && cnt2 >= 2 && cnt3 >= 1
            && cnt5 >= 1 && status) {
                ans = i;
                status = false;
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