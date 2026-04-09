#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> next(n);

    for (int i = 0; i < n; i++) {
        cin >> next[i];
        next[i]--;
    }

    vector<int> indeg(n);

    for (int i = 0; i < n; i++) {
        indeg[next[i]]++;
    }

    vector<int> cycle(n), dist(n);
    map<int, vector<int>> cycles;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            int start = -1;
            if (next[i] == i) {
                start = i;
                cycle[i] = i;
                cycles[i].push_back(i);
                continue;
            }

            int cur = i, d = 0;
            while (!vis[next[cur]]) {
                vis[next[cur]] = true;
                cur = next[cur];
                if (indeg[cur] > 0) start = cur;
                if (start == -1) d++;
            }
            
            cur = i;
            while (cur != start) {
                cycle[cur] = start;
                dist[cur] = d--;
                cur = next[cur];
            }
            
            cycle[start] = start;
            cycles[start].push_back(start);

            cout << start << " ";
            // int cnt = 0;
            while (next[cur] != start) {
                cycle[next[cur]] = start;
                cycles[start].push_back(next[cur]);
                cur = next[cur];
                // if (cnt == 0) cout << cur << " ";
                // cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ll ans = 0, len = cycles[cycle[i]].size();

        for (int j = 0; j < 100; j++) {
            ans = (ans * 10) % len;
        }

        ans = (ans - dist[i] + len) % len;

        // cout << ans << " " << len << "\n";

        cout << cycles[cycle[i]][ans] + 1 << " \n"[i == n-1]; 
    }
}