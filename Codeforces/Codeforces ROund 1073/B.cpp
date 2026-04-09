#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<int> b;
    int temp = -1;
    for (auto [k, v] : cnt) {
        if (v == 1) {
            b.push_back(k);
            temp = k;
            break;
        }
    }

    for (auto [k, v] : cnt) {
        if (k != temp) {
            for (int i = 0; i < v; i++) {
                b.push_back(k);
            }
        }
    }

    auto mex = [&](int start, int end) {
        vector<int> tmp;
        for (int i = start; i <= end; i++) tmp.push_back(b[i]);

        sort(tmp.begin(), tmp.end());
        int mex = 0;
        int i = 0;
        while (i < tmp.size()) {
            bool f = false;
            while (tmp[i] == mex) {
                f = true;
                i++;
            }
 
            if (!f) return mex;
            mex++;
        }
        return mex;
    };

    for (int i = 0; i < n - 1; i++) {
        if (mex(0, i) == mex(i+1, n-1)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}