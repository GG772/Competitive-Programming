#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    vector<int> ans;
    for (int i = 0; i < 32; i++) {
        int cur = (1 << i);
        if (((a >> i) & 1) != ((b >> i) & 1)) {
            if (cur > a) {
                cout << -1 << "\n";
                return;
            }
            ans.push_back(cur);
        }
    }

    cout << ans.size() << endl;
    if (ans.size() == 0) return;


    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}