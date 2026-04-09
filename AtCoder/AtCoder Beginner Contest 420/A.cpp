#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> month(12);
    iota(month.begin(), month.end(), 1);
    int x, y; cin >> x >> y;
    cout << month[(x - 1 + y) % 12] << endl;
    
}