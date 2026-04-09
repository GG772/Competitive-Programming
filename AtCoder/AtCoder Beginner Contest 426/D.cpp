#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n; 
    string s; cin >> s;

    vector<int> pre(n+1);
    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + (s[i] == '1');
        // cout << pre[i+1] << " ";
    }

    if (pre[n] == n || pre[n] == 0) {
        cout << 0 << endl;
        return;
    }
    

    int ans = 2 * n;
    for (int ind = 0; ind <= 1; ind++) {
        char c = '0' + ind;
        // want to change all characters into c
        vector<int> indices;
        indices.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (s[i] != c) indices.push_back(i);
        }

        indices.push_back(n);

        int len = indices.size();
        for (int i = 1; i < len; i++) {
            // char before indices[i-1] is popped from left
            // char after indices[i] is popped from right
            int a = indices[i-1], b = indices[i];
            int c1 = (a + 1 - pre[a + 1]);
            int c2 = (n - b - (pre[n] - pre[b]));
            // cout << "interval: " << a << " " << b << endl;
            // cout << "zero left: " << c1 << " zero right: " << c2 << endl;

            // cout << "one left: " << pre[a] << " one right: " << (pre[n] - pre[b]) << endl;
            if (c == '0') {
                ans = min(ans, 2 * (c1 + c2) + pre[a+1] + (pre[n] - pre[b]));
            } else {
                ans = min(ans, 2 * (pre[a+1] + (pre[n] - pre[b])) + c1 + c2);
            }
            
            // // edge case

            // ans = min(ans, 2 * c2 + )
        }
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
} 