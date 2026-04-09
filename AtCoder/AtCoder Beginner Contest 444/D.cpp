#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int main() {
    int n; cin >> n;
    vector<ll> a(N);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]--;
        a[0]++;
    }

    for (int i = 0; i < N; i++) {
        a[i+1] += a[i];
    }

    ll carry = 0;
    for (int i = 0; i < N; i++) {
        ll t = carry + a[i];
        a[i] = t % 10;
        carry = t / 10;
    }

    int m = N - 1;
    while (m >= 0 && a[m] == 0) m--;

    string ans = "";
    for (int i = 0; i <= m; i++) {
        ans += to_string(a[i]);
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}