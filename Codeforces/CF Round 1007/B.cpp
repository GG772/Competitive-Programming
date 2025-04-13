// Problem: https://codeforces.com/contest/2071/problem/B

#include <bits/stdc++.h>

using namespace std;

bool f(long long x) {
    long long r = (long long)floor(sqrt((long double)x));
    return r * r == x;
}

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n + 2);

        long long s = 0;

        for (int i = 1; i <= n; i++) {
            a[i] = i;
            s += i;
        }

        if (f(s)) {
            cout << -1 << "\n";
            continue;
        }
        
        s = 0;
        for (int i = 1; i <= n; i++) {
            if (f(s + a[i])) {
                swap(a[i], a[i+1]);
            }

            s += a[i];
            cout << a[i] << " ";
        }
        
        cout << "\n";
    }
}