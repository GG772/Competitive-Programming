#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int n;

ll area(int id) {
    int t = (id == 1 ? 2 : 1);

    int maxa = t, mina = t, maxb = t, minb = t;
    for (int i = 0; i < n; i++) {
        if (i == id) {
            continue;
        }

        if (a[maxa] < a[i]) {
            maxa = i;
        }

        if (a[mina] > a[i]) {
            mina = i;
        }

        if (b[maxb] < b[i]) {
            maxb = i;
        }

        if (b[minb] > b[i]) {
            minb = i;
        }
    }

    ll dx = a[maxa] - a[mina] + 1;
    ll dy = b[maxb] - b[minb] + 1;
    if (dx * dy == n - 1) {
        return min((dx + 1) * dy, (dy + 1) * dx);
    } else {
        return dx * dy;
    }
}


void solve() {
    cin >> n;

    int maxa = 0, mina = 0, maxb = 0, minb = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[maxa] < a[i]) {
            maxa = i;
        }

        if (a[mina] > a[i]) {
            mina = i;
        }

        if (b[maxb] < b[i]) {
            maxb = i;
        }

        if (b[minb] > b[i]) {
            minb = i;
        }
    }

    ll ans = 1e18;

    ans = min(ans, area(maxa));
    ans = min(ans, area(maxb));
    ans = min(ans, area(mina));
    ans = min(ans, area(minb));

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}