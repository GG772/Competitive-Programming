#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    string s; cin >> s;
    ll n; cin >> n;

    ll len = 0, l = s.size();

    while (1ll * l * (1ll << len) < n) {
        len++;
    }

    auto dfs = [&](auto &dfs, ll pos, ll cur) {
        if (pos < l) {
            cout << s[pos] << endl;
            return;
        }

        if (pos < cur / 2) dfs(dfs, pos, cur / 2);
        else {
            pos = (pos + (cur / 2) - 1) % (cur / 2);
            dfs(dfs, pos, cur / 2);
            return;
        }
    };

    dfs(dfs, n - 1, 1ll * l * (1ll << len));
}