#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string a, b;
int n, m;

vector<vector<vector<vector<ll>>>> memo;

ll dfs(bool flag, bool flag2, int pos, int last, bool flag3) {
    if (pos >= n) {
        return 1ll;
    }

    if (last < 10 && memo[flag][flag2][pos][last] != -1) {
        return memo[flag][flag2][pos][last];
    }

    ll ans = 0;
    int lo = 0, hi = 9;
    if (flag) {
        hi = b[pos] - '0';
    } 

    if (flag2) {
        lo = a[pos] - '0';
    }

    for (int i = lo; i <= hi; i++) {
        if (i == last && flag3) continue;
        bool f1 = flag && (i == (b[pos] - '0'));
        bool f2 = flag2 && (i == (a[pos] - '0'));
        bool f3 = (flag3 || i != 0 || pos >= n - m);
        ans += dfs(f1, f2, pos + 1, i, f3);
    }

    if (last < 10) memo[flag][flag2][pos][last] = ans;
    return ans;
}

int main() {
    cin >> a >> b;
    n = b.length();
    m = a.length();
    string tmp = string(n - m, '0');
    a = tmp + a;

    memo.assign(2, vector<vector<vector<ll>>>(2, vector<vector<ll>>(n, vector<ll>(10, -1))));
    ll ans = dfs(true, true, 0, 11, false);
    cout << ans << "\n";
}