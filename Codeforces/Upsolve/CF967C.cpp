#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int query(int a, int b) {
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> ans;

    auto search = [&](auto &search, int x, int y) -> int{
        int mid = query(x, y);
        
        if (mid == x) {
            return y;
        } 
        return search(search, x, mid);
    };
    
    for (int i = 2; i <= n; i++) {
        int fa = search(search, i, 1);
        ans.push_back({i, fa});
    }

    cout << "! ";
    for (auto [u, v] : ans) {
        cout << u << " " << v << " ";
    }

    cout << "\n";
    cout.flush();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}