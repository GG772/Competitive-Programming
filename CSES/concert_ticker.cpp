// Problem: https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    multiset<int> s;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        s.insert(tmp);
    }

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    for (int x : a) {
        auto it = s.upper_bound(x);
        if (it == s.begin()) {
            cout << "-1\n";
        } else {
            it--;
            cout << *it << "\n";
            s.erase(it);
        }
    }
}