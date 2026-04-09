#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int qry(int i, int j) {
    cout << "? " << i << " " << j << "\n";
    int ans; cin >> ans;
    return ans;
}

void print(int i) {
    cout << "! " << i << "\n";
}

void solve() {
    int n; cin >> n;
    
    int a1 = qry(1, 2);
    int a2 = qry(2, 3);
    int a3 = qry(1, 3);
    if (a1 == 1) {
        print(1);
        return;
    }

    if (a2 == 1) {
        print(2);
        return;
    }

    if (a3 == 1) {
        print(3);
        return;
    }

    for (int i = 4; i + 1 <= 2 * n; i += 2) {
        int a = qry(i, i+1);
        if (a) {
            print(i);
            return;
        }
    }
    print(2 * n);
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}