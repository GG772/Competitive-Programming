#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end(), [](const auto& a, const auto& b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    vector<int> dp(n + 1);
    
    int len = 0;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(dp.begin() + 1, dp.begin() + 1 + len, p[i].second) - dp.begin();
        if (j == len + 1) {
            dp[++len] = p[i].second;
        } else {
            dp[j] = p[i].second;
        }
    }

    cout << len << "\n";
}