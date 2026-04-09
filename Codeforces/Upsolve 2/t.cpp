#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll losingDistance(ll target, vector<ll> stations) {
    sort(stations.begin(), stations.end());
    ll pos = 0, lose = 0;
    int i = 0, n = (int)stations.size();

    while (pos < target) {
        while (i < n && stations[i] < pos) i++;          // stations behind current pos

        if (i == n || stations[i] > target) {            // no trigger before target
            lose += target - pos;
            break;
        }

        ll s = stations[i];                               // next station reached
        lose += s - pos;                                  // normal move to station
        pos = s + 10;                                     // forced move (not counted)

        while (i < n && stations[i] == s) i++;            // skip duplicates at same location
    }
    return lose;
}

int main() {
    cout << losingDistance(42, {2, 12, 22, 32}) << "\n";
}
