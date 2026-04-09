#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    map<long long, long long> cnt;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    long long ans = 0;
    for (auto [val, count] : cnt) {
        if (count >= 2) {
            ans += count * (count - 1) / 2 * (n - count);
        }
    }

    cout << ans << "\n";
    
}