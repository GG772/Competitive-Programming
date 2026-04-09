#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, q; cin >> n >> q;
    map<string, vector<string>> candidates;
    candidates["BG"] = {"BR", "BY", "GR", "GY", "BG"};
    candidates["RY"] = {"BR", "BY", "GR", "GY", "RY"};
    candidates["BR"] = {"BG", "BY", "GR", "RY", "BR"};
    candidates["GY"] = {"BG", "BY", "GR", "RY", "GY"};
    candidates["BY"] = {"BR", "BG", "RY", "GY", "BY"};
    candidates["GR"] = {"BG", "BR", "RY", "GY", "GR"};

    vector<string> a(n);
    map<string, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        string s = a[x], tmp = a[y];
        int ans = INT_MAX;
        map<string, int> cnt;
        for (string t : candidates[s]) cnt[t]++;

        for (string t : candidates[tmp]) cnt[t]++;

        for (auto [t, count] : cnt) {
            if (count < 2) continue;
            const auto& v = mp[t];
            auto it = lower_bound(v.begin(), v.end(), x);
            if (it != v.end()) {
                ans = min(ans, abs(*it - x) + abs(*it - y));
            }

            if (it != v.begin()) {
                it--;
                ans = min(ans, abs(x - *it) + abs(*it - y));
            }
        }

        if (ans == INT_MAX) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
}
