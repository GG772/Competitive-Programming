#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
    ll x, y;
};

ll cross(const point &a, const point &b) {
    return a.x * b.y - b.x * a.y;
}

ll dot(const point& a, const point& b){
    return a.x*b.x + a.y*b.y;
}

bool cmp(const point &a, const point &b) {
    int ah = (a.y < 0 or (a.y == 0 and a.x < 0));
    int bh = (b.y < 0 or (b.y == 0 and b.x < 0));
    if (ah != bh) return ah < bh;
    return cross(a, b) > 0;
}

int main() {
    int n, q; cin >> n >> q;
    vector<point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return cmp(pts[i], pts[j]);
    });

    vector<int> mp(n);
    for (int i = 0; i < n; i++) {
        mp[order[i]] = i;
    }
    
    vector<int> l(n), r(n);
    r[n - 1] = n - 1;
    for (int i = 1; i < n; i++) {
        l[i] = (cross(pts[order[i-1]], pts[order[i]]) == 0) ? l[i-1] : i;
    }

    for (int i = n - 2; i >= 0; i--) {
        r[i] = (cross(pts[order[i]], pts[order[i+1]]) == 0) ? r[i+1] : i;
    }

    for (int i = 0; i < q; i++) {
        int p1, p2; cin >> p1 >> p2;
        p1--, p2--;
        int lo = l[mp[p2]], hi = r[mp[p1]];

        if (lo <= hi) {
            cout << hi - lo + 1 << "\n";
        } else {
            cout << n - lo + hi + 1 << "\n";
        }
    }
}