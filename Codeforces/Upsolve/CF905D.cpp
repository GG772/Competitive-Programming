#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    multiset<int> left, right;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int l, r; cin >> l >> r;
        if (s == "+") {
            left.insert(l);
            right.insert(r);
        } else {
            left.erase(left.find(l));
            right.erase(right.find(r));
        }

        if (left.size() > 1) {
            int L = *left.rbegin(), R = *right.begin();
            if (L <= R) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        } else {
            cout << "No\n";
        }

    }
}

int main() {
    int t; t = 1;
    while (t--) solve();
}