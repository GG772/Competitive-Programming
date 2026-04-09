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

    vector<int> tmp;
    for (auto &[x, c] : cnt) {
        c /= 2;
        for (int j = 0; j < c; j++) {
            tmp.push_back(x);
        }
    }

    if (tmp.size() < 4) {
        cout << "NO\n";
        return;
    }
    int m = tmp.size();

    cout << "YES\n";

    cout << tmp[0] << " " << tmp[m-1] << " " << tmp[0] << " " << tmp[1] << " ";;
    cout << tmp[m-2] << " " << tmp[1] << " " << tmp[m-2] << " " << tmp[m-1] << "\n";

    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}