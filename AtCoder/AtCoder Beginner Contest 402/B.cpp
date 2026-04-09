#include <bits/stdc++.h>

using namespace std;

int main() {
    queue<int> q;
    int Q; cin >> Q;

    for (int i = 0; i < Q; i++) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int tmp; cin >> tmp;
            q.push(tmp);
        } else {
            cout << q.front() << "\n";
            q.pop();
        }
    }
}