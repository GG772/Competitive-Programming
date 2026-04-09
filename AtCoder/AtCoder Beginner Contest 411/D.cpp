#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> ver(n+5);
    vector<pair<int, string>> records(q+5);

    // store the current max record number
    int m = 0;

    while (q--) {
        int c, p; cin >> c >> p;
        if (c == 1) {
            ver[p] = ver[0];
        } else if (c == 2) {
            string s; cin >> s;
            m++;
            records[m].second = s;
            records[m].first = ver[p];
            ver[p] = m;
        } else {
            ver[0] = ver[p];
        }
    }

    int v = ver[0];
    vector<char> ans;
    while (v) {
        auto s = records[v].second;
        reverse(s.begin(), s.end());
        for (auto c : s) ans.push_back(c);
        v = records[v].first;
    }

    reverse(ans.begin(), ans.end());
    for (auto c : ans) cout << c;
    cout << "\n";
}