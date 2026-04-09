#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAXN = 1e6 + 10;

struct BIT {
    int tree[MAXN];

    BIT() {
        memset(tree, 0, sizeof(tree));
    }

    int lowbit(int x) {
        return (x & (-x));
    }

    void add(int pos, int x) {
        pos += 5e5 + 2;
        while (pos < MAXN) {
            tree[pos] += x;
            pos += lowbit(pos);
        }
    }

    // prefix qry
    int qry(int pos) {
        pos += 5e5 + 2;
        int ans = 0;
        while (pos > 0) {
            ans += tree[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }
} b;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    int sum = 0;
    ll ans = 0;

    b.add(0, 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') sum++;
        else if (s[i] == 'B') sum--;
        b.add(sum, 1);
        ans += b.qry(sum - 1);
    }
    cout << ans << "\n";
    
}