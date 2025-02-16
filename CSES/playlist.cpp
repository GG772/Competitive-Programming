#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int ans = 1, l = 0;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        int tmp = a[i];
        cnt[tmp]++;
        while (cnt[tmp] > 1) {
            cnt[a[l]]--;
            l++;
        }
        ans = max(ans, i - l + 1);
    }

    cout << ans << "\n";
}