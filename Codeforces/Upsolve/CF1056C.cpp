#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 676767677;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i-1]) > 1) {
            cout << 0 << "\n";
            return;
        }
    }

    auto t = [&](char dir) -> bool {
        vector<char> b(n);
        b[0] = dir;
        
        for (int i = 1; i < n; i++) {
            int c = a[i] - a[i-1];

            if (c == 0) {
                if (b[i-1] == '(') {
                    b[i] = ')';
                } else {
                    b[i] = '(';
                }
            } else if (c == 1) {
                b[i] = '(';
                if (b[i-1] != '(') return false;
            } else if (c == -1) {
                b[i] = ')';
                if (b[i-1] != ')') return false;
            }
        }

        vector<int> l(n), r(n);

        for (int i = 1; i < n; i++) {
            l[i] = l[i-1] + (b[i-1] == '(');
        }

        for (int i = n - 2; i >= 0; i--) {
            r[i] = r[i + 1] + (b[i+1] == ')');
        }

        // for (int i = 0; i < n; i++) {
        //     cout << l[i] << " " << r[i] << "\n";
        // }

        for (int i = 0; i < n; i++) {
            if (l[i] + r[i] + 1 != a[i]) return false;
        }

        return true;
    };

    int ans1 = t('(');
    int ans2 = t(')'); 
    // cout << ans1 << " " << ans2 << "\n";
    cout << ans1 + ans2 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}