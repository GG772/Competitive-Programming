#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> d(30);
    
    for (int i = 0; i < 30; i++) {
        unordered_map<int, ll> group_size, group_sum;
        for (int j = 0; j < n; j++) {
            ll mask = (1ll << i);
            ll mod_i = (a[j] % mask);
            ll mod_j = (mask - mod_i % mask) % mask;
            group_size[mod_i]++;
            group_sum[mod_i] += a[j];
            
            d[i] += (group_size[mod_j] * a[j] + group_sum[mod_j]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < 30; i++) {
        ans += (d[i] - d[i+1]) >> i;
    }
    cout << ans << "\n";
}