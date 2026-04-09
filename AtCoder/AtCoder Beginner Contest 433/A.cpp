#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, z; cin >> x >> y >> z;
    if ((x - z * y) % (z - 1) == 0 && (x - z * y) >= 0) cout << "Yes\n";
    else cout << "No\n";
}