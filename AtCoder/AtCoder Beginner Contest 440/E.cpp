#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    ll s = 1ll * a[0] * k;
    // tuple of sum, cnt of min element, cnt of min + 1th element, idx of min element
    priority_queue<array<ll, 4>> pq;
    pq.push({s, k, 0, 0});
    
    while (x--) {
        auto [ss, cnt0, cnt1, ind] = pq.top();
        pq.pop();

        cout << ss << "\n";
        if (ind < n - 1 && cnt0 > 0) {
            pq.push({ss - a[ind] + a[ind+1], 1, cnt0 - 1, ind + 1});
        }

        if (cnt1 > 0) {
            pq.push({ss - a[ind-1] + a[ind], cnt0 + 1, cnt1 - 1, ind});
        }
    }
}