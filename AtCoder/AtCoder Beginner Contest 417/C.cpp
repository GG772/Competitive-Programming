#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    map<int, int> cnt;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cnt[i - a[i]];
        cnt[a[i] + i]++;
    }

    cout << ans << endl;
}