// Problem: https://codeforces.com/contest/2074/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O


    int t; cin >> t;
    while (t--) {
        int x; cin >> x;

        int ans = -1;

        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                int y = (1 << i) | (1 << j);

                if (y < x && x + y > (x ^ y) && y + (x ^ y) > x) {
                    ans = y;
                }
            }
        }

        cout << ans << "\n";
        
    }
}