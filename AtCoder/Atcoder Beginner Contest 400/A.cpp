#include <bits/stdc++.h>

using namespace std;

int main () {
    int n; cin >> n;
    if (400 % n != 0) {
        cout << -1 << "\n";
    } else {
        cout << 400 / n << "\n";
    }
}