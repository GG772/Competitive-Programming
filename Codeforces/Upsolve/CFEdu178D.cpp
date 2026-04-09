#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 65 * 1e5;

vector<bool> isPrime(N, true);
vector<int> primes;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    ll s = accumulate(a.begin(), a.end(), 0ll);
    ll p = accumulate(primes.begin(), primes.begin() + n, 0ll);

    int ans = 0;
    int l = 0, r = n - 1;
    while (s < p) {
        ans++;
        s -= a[l++];
        p -= primes[r--];
    }

    cout << ans << "\n";
}

int main() {
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            for (int j = 2; j * i <= N; j++) {
                isPrime[i * j] = false;
            }
            primes.push_back(i);
        }
    }

    int t; cin >> t;
    while (t--) solve();
}