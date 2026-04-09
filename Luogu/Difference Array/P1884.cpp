#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<array<int, 4>> a(n);
    vector<ll> xs, ys;
    for (int i = 0; i < n; i++) {
        int U, L, D, R; cin >> U >> L >> D >> R;
        if (L > R) swap(L, R);
        a[i] = {U, L, D, R};
        xs.push_back(U);
        ys.push_back(L);
        xs.push_back(D);
        ys.push_back(R);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    map<int, int> rank_x, rank_y;
    int m = xs.size();
    for (int i = 0; i < m; i++) {
        rank_x[xs[i]] = i;
    }

    int k = ys.size();
    for (int i = 0; i < k; i++) {
        rank_y[ys[i]] = i;
    }

    vector<vector<ll>> f(m+5, vector<ll>(k+5));
    for (int i = 0; i < n; i++) {
        int U = rank_x[a[i][0]], L = rank_y[a[i][1]];
        int D = rank_x[a[i][2]], R = rank_y[a[i][3]];
        
        f[U][L]++;
        f[D][L]--;
        f[U][R]--;
        f[D][R]++;
    }

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            if (i - 1 >= 0) f[i][j] += f[i-1][j];
            if (j - 1 >= 0) f[i][j] += f[i][j-1];
            if (i - 1 >= 0 && j - 1 >= 0) f[i][j] -= f[i-1][j-1];

            if (i < m - 1 && j < k - 1 && f[i][j] > 0) {
                ans += (xs[i + 1] - xs[i]) * (ys[j + 1] - ys[j]);
            }
        }
    }

    cout << ans << "\n";
}
