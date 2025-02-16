// Problem: https://cses.fi/problemset/task/1621/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> st(a.begin(), a.end());
    cout << st.size() << "\n";
}