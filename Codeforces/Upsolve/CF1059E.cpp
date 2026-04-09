#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    vector<int> cnt(n + 1);

    int p = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] > 1) p = i;
    }

    if (p > -1) {
        int j = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) {
                j = i;
                break;
            }
        }

        vector<int> tmp = {j, 0, 0};

        tmp[1] = j + 1 > n ? 1 : j + 1;
        tmp[2] = a.back();

        while (tmp[1] == tmp[0] || tmp[1] == tmp[2]) {
            tmp[1] = tmp[1] + 1 > n ? 1 : tmp[1] + 1;
        }
        
        j = 0;
        for (int i = 0; i < k; i++) {
            cout << tmp[j] << " \n"[i == k-1];
            j = (j + 1) % 3;
        }
    } else {
        int j = 0;
        for (int i = 0; i < k; i++) {
            cout << a[j] << " \n"[i == k-1];
            j = (j + 1) % 3;
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}