#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    vector<int> towers;

    for (int i = 0; i < n; i++) {
        // binsearch on towers to find a fit one

        int lo = 0, hi = towers.size();

        int target; cin >> target;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (towers[mid] < target + 1) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        

        if (0 <= lo && lo < towers.size()) {
            towers[lo] = target;
        } else {
            towers.push_back(target);
        }
    }

    cout << towers.size() << "\n";
}