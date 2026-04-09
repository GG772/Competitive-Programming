#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = k - 1, mx = *max_element(a.begin(), a.end());

    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int q = (mx - a[i]) / k;
        a[i] = q * k + a[i];
        st.insert(a[i]);
    }

    ans = min(ans, *st.rbegin() - *st.begin());
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        st.erase(st.find(a[i]));
        a[i] += k;
        st.insert(a[i]);
        ans = min(ans, *st.rbegin() - *st.begin());
    }

    cout << ans << "\n";
}