#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int cnt1 = 0, cnt2 = 0;
    for (int &x : a) {
        cin >> x;
        cnt1 += (x > 0);
        cnt2 += (x < 0);
    }

    
    bool f = false;
    if (abs(cnt1 - cnt2) <= 1) {
        vector<pair<int, int>> b(n);

        int cnt = 1;

        for (int i = 0; i < n; i++) {
            b[i] = {abs(a[i]), i};
            if (i > 0 && b[i].first == b[0].first) cnt++;
        }

        if (cnt == n) {
            cout << "Yes\n";
            return;
        }

        sort(b.begin(), b.end());

        bool f1 = true;
        for (int i = 2; i < n; i++) {
            if (1ll * b[i].first * b[0].first != 1ll * b[i-1].first * b[1].first) {
                f1 = false;
                break;
            }
        }   

        bool f2 = true, f3 = true;
        for (int i = 0; i < n; i++) {
            f2 = f2 && ((i % 2 == 0 && a[b[i].second] < 0) || (i % 2 == 1 && a[b[i].second] > 0));
            f3 = f3 && ((i % 2 == 0 && a[b[i].second] > 0) || (i % 2 == 1 && a[b[i].second] < 0));
        }
        f = f || (f1 && (f2 || f3));
        // if (f) cout << "here1\n";
    }

    sort(a.begin(), a.end());
    if (cnt1 == n || cnt2 == n) {
        bool f1 = true;

        for (int i = 2; i < n; i++) {
            if (1ll * a[i] * a[0] != 1ll * a[i-1] * a[1]) {
                f1 = false;
                break;
            }
        }
        f = f || f1;
        // if (f) cout << "here2\n";
    }

    if (f) cout << "Yes\n";
    else cout << "No\n";

}
int main() {
    int t; cin >> t;
    while (t--) solve();
}