#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++) {
        arr[i] = s[i-1] - '0';
    }

    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i-1];
    }

    map<int, long long> cnt;
    for (int i = 0; i <= n; i++) {
        cnt[arr[i] - i]++;
    }

    long long ans = 0;

    for (const auto &[_, f] : cnt) {
        ans += f * (f - 1) / 2;
    }

    cout << ans << "\n";
}
int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }
}