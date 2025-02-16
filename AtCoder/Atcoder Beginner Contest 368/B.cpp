#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    while (true) {
        sort(a.begin(), a.end(), greater<int>());
        if (a[0] == 0 || a[1] == 0) {
            break;
        }
        a[0]--;
        a[1]--;
        ans++;
    }

    cout << ans;

    
}