#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    auto chk = [](int n, string t) {
        vector<pair<int, int>> a;

        int l = 0;
        bool f = false;
        while (l < n) {
            if (t[l] == '1') {
                l++;
                continue;
            }
            int r = l;
            while (r < n && t[r] == '0') {
                r++;
            }
            if (r - 1 > l) f = true;
            else a.push_back({l, r-1});
            l = r;
        }

        if (f) return true;
        else if (a.size() % 2 == 0) return true;
        else if (a[0].first == 0 && a[0].second == 0) return true;
        else if (a.back().first == n-1 && a.back().second == n-1) return true;
        return false;
    };

    bool f = true;
    int l = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '1' && s[i-1] == '1') {
            string t = s.substr(l, i - l + 1);
            f = f && chk(t.size(), t);
            l = i - 1;
        }
    }

    string t = s.substr(l);

    f = f && chk(t.size(), t);

    if (f) cout << "YES\n";
    else cout << "NO\n"; 
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}