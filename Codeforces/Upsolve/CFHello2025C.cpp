#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, r; cin >> l >> r;

    int a = 0;
    int j = 31;
    int prod = l ^ r;
    while (((prod >> j) & 1) == 0) j--;
    a = (r >> j) << j;
    int b = a - 1;
    int c = l;
    while (c == a - 1 || c == a) c++;

    cout << a << " " << b << " " << c << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}