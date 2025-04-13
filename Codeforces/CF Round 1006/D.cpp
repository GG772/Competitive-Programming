// Problem: https://codeforces.com/contest/2072/problem/D

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }


        int l = 1, r = 1;
        int cur = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = 0;
                for (int k = i + 1; k <= j; k++) {
                    tmp += (a[k] < a[i]);
                    tmp -= (a[k] > a[i]);
                }

                if (tmp > cur) {
                    cur = tmp;
                    l = i+1;
                    r = j+1;
                }
            }
        }

        cout << l << " " << r << "\n";

    }
}