#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    ll tot = 0;
    int used = 0;

    map<ll, ll> cnt;

    for (int &x : a) {
        cin >> x;
        cnt[x]++;
    }

    vector<ll> odd;
    for (auto &[val, c] : cnt) {
        if (c % 2 == 0) {
            tot += val * c;
            used += c;
        }
        else {
            tot += val * (c - 1);
            odd.push_back(val);
            used += c - 1;
        }
    }

    sort(odd.begin(), odd.end());

    ll ans = 0;
    if (used >= 3) ans = max(ans, tot);
    
    if (used >= 2) {
        for (int i = 0; i < odd.size(); i++) {
            if (tot > odd[i]) ans = max(ans, tot + odd[i]);
        }
    }

    if (used >= 1) {
        for (int i = 1; i < odd.size(); i++) {
            if (tot + odd[i-1] > odd[i]) {
                ans = max(ans, tot + odd[i] + odd[i-1]);
            }
        }
    }

    cout << ans << endl;

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}