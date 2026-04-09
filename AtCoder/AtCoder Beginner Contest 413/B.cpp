#include <bits/stdc++.h>

using namespace std;
int main() {
    int n; cin >> n;
    vector<string> a(n);

    for (string &s : a) cin >> s;
    
    set<string> st;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            st.insert(a[i] + a[j]);
        }
    }

    cout << st.size() << endl;
}