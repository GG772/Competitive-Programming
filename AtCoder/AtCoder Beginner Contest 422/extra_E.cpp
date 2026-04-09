// https://vjudge.net/contest/746472#problem/F

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
    ll a, b, c;
};

int main() {

    int n; cin >> n;
    vector<Node> p(n);

    for (Node &x : p) {
        cin >> x.a >> x.b >> x.c;
    }

    auto check = [&](int x) {
        for (Node n : p) {
            ll t1 = 1ll * x * x * x;
            ll t2 = n.a * x * x;
            ll t3 = n.b * x;
            if (t1 + t2 + t3 + n.c == 0) {
                return false;
            }
        }

        return true;
    };

    mt19937_64 rng(time(0));
    // int t = 1e6 + 1;
    int hi = 1e6 + 1;

    while (true) {
        int x = rng() % (hi);
        if (check(x)) {
            cout << x << endl;
            return 0;
        }
    }
}