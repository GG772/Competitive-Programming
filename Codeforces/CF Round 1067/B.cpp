#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n);

    map<int, int> cnt;
    for (int &x : a) {
        cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    int odd = 0;
    int c = 0;
    for (auto [k, v] : cnt) {
        if (v % 2 == 1) {
            ans++;
            odd++;
            continue;
        }

        if ((v / 2) % 2 == 1) {
            ans += 2;
        } else {
            ans += 2;
            c++;
        }
    }

    if (c % 2 && odd < 2) {
        ans -= 2;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}