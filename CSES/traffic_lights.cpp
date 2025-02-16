#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int x, n; cin >> x >> n;
    set<int> lights{0, x};
    multiset<int> dist{x};

    for (int i = 0; i < n; i++) {
        int pos; cin >> pos;
        auto it = lights.upper_bound(pos);
        auto it2 = it;
        --it2;

        dist.erase(dist.find(*it - *it2));
        dist.insert(*it - pos);
        dist.insert(pos - *it2);
        lights.insert(pos);

        auto ans = dist.end();
        --ans;
        cout << *ans << " ";
    }

    cout << "\n";

}