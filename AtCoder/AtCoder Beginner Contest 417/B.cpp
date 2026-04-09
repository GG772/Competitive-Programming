#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    multiset<int> s;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        auto it = s.find(x);
        if (it != s.end()) {
            s.erase(s.find(x));
        }
    }

    for (int x : s) {
        cout << x << " ";
    }
}