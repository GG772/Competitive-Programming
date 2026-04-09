#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> odd, even;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 2) odd.push_back(x);
        else even.push_back(x);
    }

    sort(odd.begin(), odd.end(), greater<>());
    sort(even.begin(), even.end(), greater<>());

    int l1 = odd.size(), l2 = even.size();

    vector<ll> pre(l2+1);

    for (int i = 0; i < l2; i++) pre[i+1] = pre[i] + even[i];

    for (int i = 1; i <= n; i++) {
        if (l1 == 0) {
            cout << "0 ";
            continue;
        } else if (l2 == 0) {
            if (i % 2 == 1) {
                cout << odd[0] << " ";
            } else {
                cout << "0 ";
            }
            continue;
        }

        if (l2 >= i - 1) {
            ll ans = odd[0] + pre[i - 1];
            cout << ans << " ";
        } else {
            int rem = l2;
            if ((i - rem - 1) % 2 == 1) {
                rem--;
                if (i - rem > l1) {
                    cout << 0 << " ";
                    continue;
                }
            }

            cout << odd[0] + pre[rem] << " ";
        }

    }
    
    cout << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}