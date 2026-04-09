#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e14;

int main() {
    int n; cin >> n;
    set<ll> st;
    st.insert(0);

    map<int, ll> dist;
    dist[0] = 1e10;
    
    ll ans = 1e10;

    auto query = [&](ll val) -> void {
        auto it = st.lower_bound(val);
        auto it2 = prev(it);

        dist[val] = ll(1e10);

        if (it != st.end()) {
            ans -= dist[*it];
            dist[*it] = min(dist[*it], *it - val);
            ans += dist[*it];
            dist[val] = min(dist[val], *it - val);
        }

        if (it != st.begin()) {
            ans -= dist[*it2];
            dist[*it2] = min(dist[*it2], val - *it2);
            ans += dist[*it2];
            dist[val] = min(dist[val], val - *it2);
        }

        st.insert(val);
        ans += dist[val];
        cout << ans << "\n";
        
    };

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        query(x);
    }
    
}