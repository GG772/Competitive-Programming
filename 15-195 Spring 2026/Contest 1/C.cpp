#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 rng(std::random_device{}());
    
    int m; cin >> m;

    for (int k = 0; k < m; k++) {
        int n = 2 + k;
        uniform_int_distribution<int> dist(1, n-1);
        for (int i = 2; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cout << "? " << i << " " << j << "\n";
                cout << "? " << i - 1 << " " << j << "\n";
            }
        }
        int x = dist(rng);
        cout << "! " << x << " " << x+1 << "\n";
    }
}