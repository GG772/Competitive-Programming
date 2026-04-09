#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    map<string, set<int>> cnt;
    for (int i = 0; i < q; i++) {
        char x, y; cin >> x >> y;
        if (x == 'a') {
            continue;
        }
        string tmp = "aa";
        tmp[0] = x, tmp[1] = y;
        cnt[tmp].insert(i);
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            // case ba
            if (cnt["ba"].size() > 0) {
                cnt["ba"].erase(cnt["ba"].begin());
                s[i] = 'a';
            } else if (cnt["bc"].size() > 0) {
                int ind = *cnt["bc"].begin();
                auto it1 = cnt["ca"].lower_bound(ind);
                if (it1 != cnt["ca"].end()) {
                    cnt["bc"].erase(ind);
                    cnt["ca"].erase(it1);
                    s[i] = 'a';
                }
            }
        } else if (s[i] == 'c') {
            // case ca
            if (cnt["ca"].size() > 0) {
                cnt["ca"].erase(cnt["ca"].begin());
                s[i] = 'a';
            } else if (cnt["cb"].size() > 0){
                int ind = *cnt["cb"].begin();
                auto it1 = cnt["ba"].lower_bound(ind);
                if (it1 != cnt["ba"].end()) {
                    cnt["cb"].erase(ind);
                    cnt["ba"].erase(it1);
                    s[i] = 'a';
                } else {
                    s[i] = 'b';
                    cnt["cb"].erase(ind);
                }
            } 
        }
    }

    cout << s << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}