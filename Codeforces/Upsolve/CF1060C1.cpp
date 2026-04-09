#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
vector<vector<int>> primes(N);
vector<bool> isP(N, true);

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int ans = 2;
    map<int, int> mp;

    // check for cost 0
    for (int x : a) {
        for (int p : primes[x]) {
            if (p > x) break;
            bool f = true;
            while (x % p == 0) {
                if (f && mp.count(p)) {
                    cout << 0 << "\n";
                    return;
                } 
                mp[p] = 1;
                f = false;
                x /= p;
            }
        }
    }

    // check for cost 1
    for (int x : a) {
        int t = x + 1;
        for (int p : primes[t]) {
            if (p > t) break;
            bool f = true;
            
            while (t % p == 0) {
                if (f && mp.count(p)) {
                    cout << 1 << "\n";
                    return;
                } 
                f = false;
                t /= p;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i <= N; i++) {
        if (isP[i]) {
            for (int j = 1; i * j <= N; j++) {
                if (j > 1) isP[i * j] = false;
                primes[i * j].push_back(i);
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        solve();
    }
}