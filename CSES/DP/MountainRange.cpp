#include <bits/stdc++.h>

using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> left(n, -1), right(n, n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }

        if (!st.empty()) {
            left[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }

        if (!st.empty()) {
            right[i] = st.top();
        }
        st.push(i);
    }

    vector<int> dp(n, 1);
    vector<int> indices(n);

    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return a[i] > a[j];
    });

    int ans = 1;
    for (int j : indices) {
        int l = left[j], r = right[j];
        if (l >= 0) {
            dp[j] = max(dp[j], 1 + dp[l]);
        }
        if (r < n) {
            dp[j] = max(dp[j], 1 + dp[r]);
        }
        ans = max(ans, dp[j]);
    }

    cout << ans << "\n";
}