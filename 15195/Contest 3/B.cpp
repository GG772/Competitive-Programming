#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<long long> window;
    multiset<long long>::iterator mid;

    for(int i = 0; i < n; i++) {
        if(window.size() == 0) {
            window.insert(a[i]);
            mid = window.begin();
        } else {
            window.insert(a[i]);
            if(a[i] < *mid) {
                if(k % 2 == 1) {
                    // Window size will become odd after insertion
                    --mid;
                }
                // Else, mid remains the same
            } else {
                if(k % 2 == 0) {
                    // Window size will become even after insertion
                    ++mid;
                }
                // Else, mid remains the same
            }
        }

        if(window.size() > k) {
            long long out_elem = a[i - k];
            if(out_elem <= *mid) {
                if(k % 2 == 1) {
                    // Window size will become even after removal
                    ++mid;
                }
                // Else, mid remains the same
            } else {
                if(k % 2 == 0) {
                    // Window size will become odd after removal
                    --mid;
                }
                // Else, mid remains the same
            }
            window.erase(window.lower_bound(out_elem));
        }

        if(window.size() >= k) {
            cout << *mid << " ";
        }
    }
    cout << endl;
    return 0;
}
