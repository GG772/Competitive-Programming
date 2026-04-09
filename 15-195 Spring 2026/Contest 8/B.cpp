#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    int ans = 1e9;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<int> st;
    int l = 0;
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
        if (st.size() < k) continue;
        
        // cout << *(--st.end()) << " ";
        ans = min(ans, *(--st.end()));
        st.erase(a[l++]);
    }
    
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}