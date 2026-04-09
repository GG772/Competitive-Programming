#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 2e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> stk, b;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && stk.back() > a[i]) {
            b.push_back(stk.back() + 1);
            stk.pop_back();
        }
        stk.push_back(a[i]);
    }

    sort(b.begin(), b.end());
    while (!stk.empty() && !b.empty() && stk.back() > b[0]) {
        b.push_back(stk.back() + 1);
        stk.pop_back();
    }

    sort(b.begin(), b.end());
    for (int x : stk) cout << x << " ";
    for (int x : b) cout << x << " ";
    cout << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}