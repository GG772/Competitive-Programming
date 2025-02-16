// Problem: https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    unordered_set<int> st;
    for (int i = 0; i < n - 1; i++) {
        int tmp; cin >> tmp;
        st.insert(tmp);
    }
    for (int i = 1; i <= n; i++) {
        if (st.find(i) == st.end()) {
            cout << i << "\n";
        }
    }
}