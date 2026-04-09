#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    map<int, int> cnt;
    
    vector<int> ans(n+2);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int mex = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            break;
        }
        mex++;
    }


    for (int i = 0; i <= mex; i++) {
        if (cnt.count(i)) {
            int l = cnt[i], r = n - i;
            assert(r <= n);
            ans[l]++;
            ans[r+1]--;
        }
    }

    int s = 0;
    for (int i = 0; i <= n; i++) {
        s += ans[i];

        if (i == 0) {
            cout << 1 << " \n"[i == n];
        } else {
            cout << s << " \n"[i == n];
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}