#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, p, m; cin >> n >> k >> p >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    multiset<int> st1;
    deque<int> st2;
    int cost = a[p-1];

    for (int i = 0; i < n; i++) {
        if (i < k) {
            st1.insert(a[i]);
        } else {
            st2.push_back(a[i]);
        }
    }

    int energy = 0, ans = 0;
    while (energy <= m) {
        int cur = *st1.begin();
        if (p <= k) {
            cur = cost;
        }
        if (energy + cur > m) {
            break;
        }
        if (p <= k) {
            ans++;
            p = n;
        } else {
            p--;
        }
        st1.erase(st1.find(cur));
        st2.push_back(cur);
        int nxt = st2.front();
        st2.pop_front();
        st1.insert(nxt);
        
        energy += cur;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}