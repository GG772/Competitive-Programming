#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n), cnt(n), p;
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
        if (cnt[a[i]] <= k) {
            p.push_back(i);
        }
    }

    while (int(p.size()) % k > 0) {
        p.pop_back();
    }

    sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });

    for (int i = 0; i < p.size(); i++) {
        ans[p[i]] = i % k + 1;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    
}

