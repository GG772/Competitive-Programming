#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e18;
const int N = 2e6;

void solve(vector<int> primes) {
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << primes[i] << " ";
        } else {
            cout << (1ll * primes[i-1] * primes[i]) << " ";
        }
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    vector<int> primes;
    vector<bool> isP(N + 1, true);

    for (int i = 2; i <= N; i++) {
        if (isP[i]) {
            primes.push_back(i);
            for (int j = 2; i * j <= N; j++) {
                isP[i * j] = false;
            }
        }
    }

    while (t--) solve(primes);
}