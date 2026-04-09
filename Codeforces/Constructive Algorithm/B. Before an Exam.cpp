// Problem: https://codeforces.com/problemset/problem/4/B
#include <bits/stdc++.h>

using namespace std;

int main() {
    int d, s; cin >> d >> s;
    
    vector<int> a(d), b(d);
    int s1 = 0, s2 = 0;
    for (int i = 0; i < d; i++) {
        cin >> a[i] >> b[i];

        s1 += a[i];
        s2 += b[i];
    }

    int diff = s - s1;

    if (s1 > s || s2 < s) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    vector<int> ans(d);

    for (int i = 0; i < d; i++) {
        ans[i] = a[i];
    }
    int l = 0;
    while (diff > 0) {
        if (diff > b[l] - a[l]) {
            ans[l] = b[l];
            diff -= (b[l] - a[l]);
            l++;
        } else {
            ans[l] += diff;
            break;
        }
    }

    for (int i = 0; i < d; i++) {
        cout << ans[i] << " ";
    }
}