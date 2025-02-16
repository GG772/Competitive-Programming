// Problem: https://cses.fi/problemset/task/2217

#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<int> seq(n+1);
    vector<int> pos(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
        pos[seq[i]] = i;
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans += (pos[i] < pos[i-1]);
    }

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;

        int x = seq[a], y = seq[b];

        set<int> ind;

        ind.insert(x-1);
        ind.insert(x);
        ind.insert(y-1);
        ind.insert(y);

        // before swapping, subtract the numbers within the pos

        for (int j : ind) {
            if (pos[j] > pos[j+1]) {
                ans--;
            }
        }

        swap(seq[a], seq[b]);
        swap(pos[x], pos[y]);

        for (int j : ind) {
            if (pos[j] > pos[j+1]) {
                ans++;
            }
        }

        cout << ans << "\n";
        
    }
}