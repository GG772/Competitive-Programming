#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x; cin >> n >> x;

    vector<int> arr(n);
    vector<long long> pre(n+1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pre[i+1] = pre[i] + arr[i];
    }

    long long ans = 0;

    map<long long, int> cnt;
    cnt[0] = 1;

    for (int i = 1; i <= n; i++) {
        ans += cnt[pre[i] - x];
        cnt[pre[i]]++;
    }

    cout << ans << "\n";


}