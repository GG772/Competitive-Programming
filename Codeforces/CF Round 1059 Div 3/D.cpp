#include <bits/stdc++.h>

using namespace std;

int ask(int t, int l, int r) {
    cout << t << " " << l << " " << r << endl;
    cout.flush();

    int res; cin >> res;
    return res;
}

void solve() {
    int n; cin >> n;

    int lo = -1, hi = -1;
    map<tuple<int, int, int>, int> mp;
    auto dfs1 = [&](auto &dfs1, int l, int r) -> void {
        if (l >= r) {
            lo = l;
            return;
        } 
        int mid = (l + r) >> 1;
        int res1, res2;
        if (!mp.count({1, 1, mid})) {
            res1 = ask(1, 1, mid);
            mp[{1, 1, mid}] = res1;
        } else {
            res1 = mp[{1, 1, mid}];
        }
        
        if (!mp.count({2, 1, mid})) {
            res2 = ask(2, 1, mid);
            mp[{2, 1, mid}] = res2;
        } else {
            res2 = mp[{2, 1, mid}];
        }

        if (res1 == res2) {
            l = mid + 1;
        } else {
            r = mid;
        }
        dfs1(dfs1, l, r);
    };


    dfs1(dfs1, 1, n+1);
    int len = ask(2, 1, n) - ask(1, 1, n);
    cout << "! " << lo << " " << lo + len - 1 << endl;
    cout.flush();
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}