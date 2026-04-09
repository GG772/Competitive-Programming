#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    ll px, py, qx, qy; cin >> px >> py >> qx >> qy;
    vector<double> a(n);

    double s = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    ll d1 = px - qx, d2 = py - qy;

    double dist = sqrt(d1 * d1 + d2 * d2);
    a.push_back(dist);
    sort(a.begin(), a.end());

    s += dist;
    if (a[n] <= s - a[n]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}