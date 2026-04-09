#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

void solve() {
    int q; cin >> q;

    deque<int> dq1, dq2;
    ll fsum = 0, rsum = 0, sum = 0;

    while (q--) {
        int op; cin >> op;
        if (op == 3) {
            int k; cin >> k;
            
            dq1.push_back(k);
            dq2.push_front(k);
            fsum += 1ll * dq1.size() * k;
            rsum += sum + k;
            sum += k;
        } else if (op == 2) {
            swap(dq1, dq2);
            swap(fsum, rsum);
        } else {
            int last = dq1.back();
            dq1.pop_back();
            dq1.push_front(last);
            fsum = fsum + (sum - last) - 1ll * (dq1.size() - 1) * last;

            last = dq2.front();
            dq2.pop_front();
            dq2.push_back(last);
            
            rsum = rsum - (sum - last) + 1ll * (dq2.size() - 1) * last;
        }

        cout << fsum << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}