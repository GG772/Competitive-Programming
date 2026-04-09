#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dig() {
    cout << "digit" << endl;
    fflush(stdout);
    int res; cin >> res;
}

int add(int x) {
    cout << "add " << x << endl;
    fflush(stdout);
    int res; cin >> res;
    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        dig();
        dig();
        int res;
        // now x is in range [1, 16]
        for (int i = 8; i >= 1; i /= 2) {
            res = add(-1 * i);
        }
        res = add(n-1);
        cout << "!" << endl;
        fflush(stdout);
        cin >> res;
        if (res == -1) return 0;
    }
}