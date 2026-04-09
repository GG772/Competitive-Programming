#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int t) {
    int n, a, b; cin >> n >> a >> b;
    cout << "Case #" << t << ": ";
    for (int i = 0; i < 2 * n - 1; i++) {
        cout << 1 << " ";
    }

    cout << b << "\n";
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}