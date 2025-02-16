// Problem: https://cses.fi/problemset/submit/1074/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans += abs(a[n/2] - a[i]);
    }

    cout << ans << "\n";
}