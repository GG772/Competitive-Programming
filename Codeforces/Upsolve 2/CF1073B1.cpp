#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> suf(n + 1), next(n, n);

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i+1] + (s[i+1] == '(');
    }

    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') st.push(i);
        else {
            while (!st.empty()) {
                int j = st.top();
                st.pop();
                next[j] = i;
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != ')') continue;
        
        int j = next[i];
        if (suf[j] >= j - i) {
            ans = max(ans, n - 2 * (j - i));
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}