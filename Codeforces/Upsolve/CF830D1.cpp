#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    set<ll> st1, st2;

    for (int i = 1; i <= n + 1; i++) {
        st2.insert(i);
    }

    for (int i = 0; i < n; i++) {
        string op; cin >> op;
        ll x; cin >> x;
        if (op == "+") {
            st.insert(x);
            
        }
    }
}

int main() {
    int t; t = 1;
    while (t--) solve();
}