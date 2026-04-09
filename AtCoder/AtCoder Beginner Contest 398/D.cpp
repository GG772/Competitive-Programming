#include <bits/stdc++.h>

using namespace std;

int main() {
    // move both the fire and T
    // use set/map so that check the smoke
    // on cell[i, j] takes logN time

    int n, r, c; cin >> n >> r >> c;
    string s; cin >> s;
    // r = r * -1;

    set<pair<int, int>> st;

    int fx = 0, fy = 0;

    st.insert({0, 0});

    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') {
            r++;
            fx++;
        } else if (s[i] == 'S') {
            r--;
            fx--;
        } else if (s[i] == 'W') {
            c++;
            fy++;
        } else {
            c--;
            fy--;
        }
        st.insert({fx, fy});
        // cout << fx << " " << fy << "\n";
        if (st.find({r, c}) != st.end()) {
            cout << 1;
        } else {
            cout << 0;
        }
    }

    cout << "\n";
}