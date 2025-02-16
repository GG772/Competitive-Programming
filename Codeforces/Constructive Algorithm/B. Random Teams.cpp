#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m; cin >> n >> m;
    long long res = n - m;
    long long k_max = 1ll * res * (1 + res) / 2;
    long long q = n / m, r = n % m;
    long long k_min = 1ll * (q + 1) * q / 2 * r + 1ll * q * (q - 1) / 2 * (m - r);
    cout << k_min << " " << k_max << "\n";
}