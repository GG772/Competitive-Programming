#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    queue<pair<int, int>> q;
    int n; cin >> n;
    while (n--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int c, x; cin >> c >> x;
            q.emplace(x, c);
        } else {
            int k; cin >> k;
            ll s = 0;
            while (!q.empty() && q.front().second <= k) {
                k -= q.front().second;
                s += 1ll * q.front().first * q.front().second;
                q.pop();
            }

            if (!q.empty()) {
                q.front().second -= k;
                s += 1ll * q.front().first * k;
            }

            cout << s << endl;
        }
    }
}