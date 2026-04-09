#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 305;

int main() {
    int t; cin >> t;
    vector<bool> isPrime(N, true);
    vector<int> primes;

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            for (int j = 2; i * j <= N; j++) {
                isPrime[i * j] = false;
            }
            primes.push_back(i);
        }
    }


    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);

        for (ll &x : a) cin >> x;
        bool f = false;
        for (int p : primes) {
            for (ll x : a) {
                if (x % p != 0) {
                    cout << p << "\n";
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
        if (!f) cout << -1 << "\n";
    }
}