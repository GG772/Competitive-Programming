#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n * 2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n; i < n * 2 - 1; i++) {
        a[i] = a[i - n];
    }

    vector<int> prefix(n * 2 + 1);

    for (int i = 0; i < n * 2; i++) {
        prefix[i+1] = (prefix[i] + a[i]) % m;
    }

    // count occurrences of pref_0 ... pref_n - 1

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[prefix[i]]++;
    }

    long long ans = 0;

    for (int i = n; i < 2 * n; i++) {
        cnt[prefix[i-n]]--;
        ans += cnt[prefix[i]];
        cnt[prefix[i]]++;
    }

    cout << ans << "\n";
}

int main() {
    solve();

}