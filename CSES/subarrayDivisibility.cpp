#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    long long preSum = 0;
    long long ans = 0;

    map<long long, int> cnt;
    cnt[0] = 1;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;

        preSum += tmp;

        int rem = (preSum % n + n) % n;

        ans += cnt[rem];
        cnt[rem]++;
    }

    cout << ans << "\n";
}