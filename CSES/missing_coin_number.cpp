// Problem: https://cses.fi/problemset/task/2183

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 1; // the min number that can't be formed using a[1] ... a[i]
    bool b = true;

    for (int i = 0; i < n; i++) {
        if (a[i] > ans) {
            cout << ans << "\n";
            b = false;
            break;
        } else {
            ans += a[i];
        }
    }

    if (b) {
        cout << ans << "\n";
    } 
}