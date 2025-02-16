#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    int x = a.first, y = b.first;
    return x < y;
}
 
int main() {
    int n; cin >> n;

    vector<int> start(n), end(n);

    for (int i = 0; i < n; i++) {
        cin >> start[i];
        cin >> end[i];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int si = 0, ei = 0, cur = 0, ans = 0;

    while (si < n - 1) {
        if (end[ei] <= start[si]) {
            cur--;
            ei++;
        } else {
            cur++;
            si++;
        }
        ans = max(ans, cur);
    }

    if (end[ei] > start[si]) {
        cur++;
        si++;
        ans = max(ans, cur);
    }

    cout << ans << "\n";
}