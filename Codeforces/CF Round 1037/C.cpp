#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    k--;

    vector<long long> h(n);

    for (int i = 0; i < n; i++) cin >> h[i];
    int cur = h[k];
    sort(h.begin(), h.end());
    if (cur == h[n-1]) {
        cout << "yes\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (h[i] == cur) {
            cur = i;
            break;
        }
    }


    long long water = 1;
    while (cur < n - 1) {
        if (water > h[cur]) {
            cout << "no\n";
            return;
        } else if (water + h[cur + 1] - h[cur] - 1 > h[cur]) {
            cout << "no\n";
            return;
        } else {
            water += h[cur + 1] - h[cur];
            cur++;
        }
    }

    cout << "yes\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}