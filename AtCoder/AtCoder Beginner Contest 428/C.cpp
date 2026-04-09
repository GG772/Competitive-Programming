#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; cin >> q;
    int s = 0;
    stack<char> ans;    
    vector<int> a(1), b(1);
    for (int i = 0; i < q; i++) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            char c; cin >> c;
            a.push_back(a.back() + (c == '(' ? 1 : -1));
            b.push_back(min(a.back(), b.back()));
        } else {
            a.pop_back();
            b.pop_back();
        }

        if (a.back() == 0 && b.back() == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}