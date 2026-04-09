#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    vector<int> left(n), right(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                left[j]++;
            }
            if (a[j] > a[i]) {
                right[i]++;
            }
        }
    }

    int inv = 0;

    for (int i = 0; i < n; i++) {
        inv += min(left[i], right[i]);
    }

    cout << inv << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}