// Problem: https://codeforces.com/problemset/problem/492/B
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    double l; cin >> l;

    vector<double> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double diff = 0;

    for (int i = 1; i < n; i++) {
        diff = max(diff, (a[i] - a[i-1]));
    }

    cout << fixed << setprecision(10)
         << max(diff / 2.0, max(a[0], l - a[n-1])) << "\n";
}