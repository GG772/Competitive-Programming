// Problem: https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> f(n);

    f[0] = nums[0];
    long long ans = nums[0];

    for (int i = 1; i < n; i++) {
        f[i] = max(f[i-1], 0ll) + nums[i];
        ans = max(ans, f[i]);
    }
    cout << ans << "\n";
}