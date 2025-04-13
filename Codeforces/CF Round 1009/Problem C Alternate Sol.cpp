// Problem: https://codeforces.com/contest/2074/problem/A
// Solution: https://www.bilibili.com/video/BV1oeQ5YqEur/?spm_id_from=333.337.search-card.all.click&vd_source=640aa11f791ae9a99ca713def1fd8606

#include <bits/stdc++.h>

using namespace std;

int bit_width(unsigned int n) {
    int count = 0;
    while (n != 0) {
        n >>= 1;
        count++;
    }
    return count;
}
  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;

        int w = bit_width(unsigned(x));

        int y = (1 << (w - 1)) - 1;

        int z = x ^ y;

        if (y < x && x + y > z && x + z > y && y + z > x) {
            cout << y << "\n";
        } else {
            cout << -1 << "\n";
        }
        
    }
}