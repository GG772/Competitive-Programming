#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 1;

vector<bool> isPrime(MAXN, true);
vector<int> primes;
void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);

    int cnt2 = 0;
    int mx = 0;
    for (int &x : a) {
        cin >> x;
        cnt2 += (x % 2 == 0);
        mx = max(mx, x);
    }

    for (int &x : b) cin >> x;
    if (cnt2 >= 2) {
        cout << 0 << endl;
        return;
    }

    int ans = 2;
    map<int, bool> fac;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (x == 1) continue;
        for (int p : primes) {
            int cnt = 0;
            while (x % p == 0) {
                if (fac[p] && cnt == 0) {
                    cout << 0 << endl;
                    return;
                }
                fac[p] = true;
                cnt = 1;
                x /= p;
            }
            if (p > x) break;
        }
    }

    // check for cost 1

    for (int i = 0; i < n; i++) {
        int x = a[i] + 1;
        for (int p : primes) {
            while (x % p == 0) {
                if (fac[p]) {
                    cout << 1 << endl;
                    return;
                } 
                x /= p;
            }
            if (p > x) break;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = 2; i * j <= MAXN; j++) {
                isPrime[i * j] = false;
            }
            primes.push_back(i);
        }
    } 
     
    int t; cin >> t;
    while (t--) solve();
}