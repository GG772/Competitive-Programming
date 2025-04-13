// Problem: https://codeforces.com/contest/2072/problem/E

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O

    int t; cin >> t;

    while (t--) {
        int k; cin >> k;
        int x = 0, y = 0;
        int sum = 0, cur = 0;

        if (k == 0) {
            cout << "1\n";
            cout << "0 0\n";
            continue;
        }

        vector<pair<int, int>> a;

        while (sum != k) {
            while (sum + cur <= k) {
                sum = sum + cur;
                cur++;

                // cout << sum << " " << cur << "\n";
                
                a.push_back({x, y});
                // cout << x << " " << y << "\n";
                x++;
            }
            cur = 0;
            y++;
        }

        cout << a.size() << "\n";
        for (auto &p : a) {
            cout << p.first << " " << p.second << "\n";
        }

    }
}