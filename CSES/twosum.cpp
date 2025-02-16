// Problem: https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;

    map<int, int> mp;

    int ans1 = -1, ans2 = -1;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if (mp.find(x - tmp) != mp.end()) {
            ans1 = i;
            ans2 = mp[x - tmp];
        } else {
            mp[tmp] = i;
        }
    }

    if (ans1 == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans1+1 << " " << ans2+1;
    }
}