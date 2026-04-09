#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int cnt = 0;

    stack<int> s;

    array<int, 2> b;
    b[0] = -1, b[1] = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (s.empty() || s.top() <= a[i]) s.push(a[i]);
        else if (!s.empty() && a[i] < s.top()) {
            b[0] = s.top();
            b[1] = a[i];
        }
    }

    if (b[0] == -1 && b[1] == -1) {
        cout << "No\n";
    } else {
        cout << "Yes\n2\n";
        cout << b[0] << " " << b[1] << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}