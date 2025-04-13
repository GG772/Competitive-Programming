#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void answer(int i, int j, int k) {
    cout << "! " << i << " " << j << " " << k << endl << flush;
}

int ask(int i, int j, int k) {
    cout << "? " << i << " " << j << " " << k << endl << flush;
    int r; cin >> r;
    if (r == 0) answer(i, j, k);
    return r;
}

void solve() {
    srand(time(0));
    
    int n; cin >> n;
    if (n == 3) {
        answer(1, 2, 3);
        return;
    }
    vector<int> a{1, 2, 3};

    while (true) {
        int r = ask(a[0], a[1], a[2]);
        if (r == 0) return;

        int x = rand() % 3;

        int y = (x + 1) % 3, z = (x + 2) % 3;

        int r1 = ask(r, a[x], a[y]);
        if (r1 == 0) return;
        int r2 = ask(r, a[x], a[z]);
        if (r2 == 0) return;
        a = {r, r1, r2};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/Os
    int t; cin >> t;

    while (t--) {
        solve();
    }
}