#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 90;
const ll cap = 2e18;

int main() {
    string x, y; cin >> x >> y;
    int q; cin >> q;
    ll n = x.length(), m = y.length();

    vector<array<ll, 26>> pre1(n + 1), pre2(m + 1), total(N + 1);
    vector<ll> len(N + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            pre1[i+1][j] = pre1[i][j] + ((x[i] - 'a') == j);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 26; j++) {
            pre2[i+1][j] = pre2[i][j] + ((y[i] - 'a') == j);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == 1) {
                total[i][j] = pre1[n][j];
            } else if (i == 2) {
                total[i][j] = pre2[m][j];
            } else {
                total[i][j] = total[i-1][j] + total[i-2][j];
            }
        }
        if (i == 1) {
            len[i] = n;
        } else if (i == 2) {
            len[i] = m;
        } else {
            if (len[i-1] >= cap / 2 && len[i-2] >= cap / 2) {
                len[i] = cap;
            } else {
                len[i] = len[i-1] + len[i-2];
            }
        }
    }

    auto count = [&](auto &&count, int n, ll k, char c) {
        if (k <= 0) return 0ll;

        if (n == 1) {
            return pre1[min(ll(x.length()), k)][c - 'a'];
        }

        if (n == 2) {
            return pre2[min(m, k)][c - 'a'];
        }

        ll l = len[n - 1];
        if (k > l) {
            return total[n - 1][c - 'a'] + count(count, n - 2, k - l, c);
        } else {
            return count(count, n - 1, k, c);
        }
    };

    for (int i = 0; i < q; i++) {
        ll l, r; cin >> l >> r;
        char c; cin >> c;
        cout << count(count, N, r, c) - count(count, N, l-1, c) << "\n";
    }
}