// Problem: https://codeforces.com/problemset/problem/776/B
#include <bits/stdc++.h>

using namespace std;
int main() {
    int n; cin >> n;
    vector<int> p(n + 5);
    bool f = false;
    for (int i = 2; i <= n + 1; i++) {
        if (p[i] == 1) {
            f = true;
            continue;
        }
        for (int j = 2; i * j <= n + 1; j++) {
            p[i * j] = 1;
        }
    }

    if (!f) {
        cout << 1 << "\n";
        for (int i = 1; i <= n; i++) {
            cout << 1 << " ";
        }
    } else {
        cout << 2 << "\n";
        for (int i = 1; i <= n; i++) {
            if (p[i+1] == 0) {
                cout << 2 << " ";
            } else {
                cout << 1 << " ";
            }
        }
    }


}