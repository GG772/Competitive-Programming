#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int m = 1e9 + 7;

void solve() {
    string s; cin >> s;
    int n = s.length(), sum = 0;
    map<int, vector<int>> cnt;
    cnt[0].push_back(0);
    vector<int> pre(n+1);
    for (int i = 0; i < n; i++) {
        sum += (s[i] == '1');
        sum -= (s[i] == '0');
        cnt[sum].push_back(i + 1);
        pre[i+1] = sum;
    }

    vector<ll> contribution(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (contribution[i] > -1) continue;
        const auto& v = cnt[pre[i]];

        int t = v.size();
        int ptr = t - 1;

        ll csum = 0;
        while (ptr > 0) csum += (n - v[ptr--] + 1);
        csum %= m;
        
        for (int i = 0; i < t - 1; i++) {
            contribution[v[i]] = (csum * (v[i] + 1) % m) % m;
            csum = (csum - (n - v[i+1] + 1)) % m;
            csum = (csum + m) % m;
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        if (contribution[i] > -1) ans = (ans + contribution[i]) % m;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
}
