#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; cin >> q;
    priority_queue<int, vector<int>, greater<>> pq;


    for (int i = 0; i < q; i++) {
        int c; cin >> c;
        if (c == 1) {
            int x; cin >> x;
            pq.push(x);
        } else {
            cout << pq.top() << "\n";
            pq.pop();
        }
    }
}