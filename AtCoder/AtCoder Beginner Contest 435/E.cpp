#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    set<pair<int, int>> intervals;

    int cnt = 0;
    for (int i = 0; i < Q; i++) {
        int L, R; cin >> L >> R;
        auto it = intervals.lower_bound({L, -1});
        if (it != intervals.begin()) {
            if (prev(it)->second >= L) --it;
        }

        int l = L, r = R;
        while (it != intervals.end()) {
            auto [x, y] = *it;
            if (x > R) break;
            
            l = min(l, x);
            r = max(r, y);
            cnt -= (y - x + 1);
            it = intervals.erase(it);
        }

        cnt += r - l + 1;
        intervals.insert({l, r});
        cout << N - cnt << "\n";
    }
}