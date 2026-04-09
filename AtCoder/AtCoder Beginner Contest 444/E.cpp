#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, d; cin >> n >> d;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];

    int r = 0;
    ll ans = 0;
    set<int> st;
    for (int l = 0; l < n; l++) {
        while (r < n) {
            if (st.count(a[r])) break;
            auto it = st.insert(a[r]).first;

            if (it != st.begin() && a[r] - *prev(it) < d) {
                st.erase(it);
                break;
            }

            if (it != st.end() && next(it) != st.end() && *next(it) - a[r] < d) {
                st.erase(it);
                break;
            }
            r++;
        }

        ans += st.size();
        st.erase(st.find(a[l]));
    }

    cout << ans << "\n";
}