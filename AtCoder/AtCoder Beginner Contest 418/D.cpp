#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    string t; cin >> t;
    ll ans = 0;

    vector<int> cnt(2);
    cnt[0] = 1;
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += (t[i] == '0');
        s %= 2;
        ans += cnt[s];
        cnt[s]++;
    }

    cout << ans << endl;
}