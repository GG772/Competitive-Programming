#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b; cin >> a >> b;

    int cur = 1, turn = 0;
    int t1 = a, t2 = b;

    while ((turn % 2 == 0 && t1 >= cur) || (turn % 2 == 1 && t2 >= cur)) {
        if (turn % 2 == 0) t1 -= cur;
        else t2 -= cur;
        turn++;
        cur <<= 1;
    }

    int ans1 = turn;

    t1 = b, t2 = a;
    turn = 0;
    cur = 1;

    while ((turn % 2 == 0 && t1 >= cur) || (turn % 2 == 1 && t2 >= cur)) {
        if (turn % 2 == 0) t1 -= cur;
        else t2 -= cur;
        turn++;
        cur <<= 1;
    }
    cout << max(ans1, turn) << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}