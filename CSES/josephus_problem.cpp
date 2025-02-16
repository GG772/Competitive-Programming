#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    } else if (n == 2) {
        cout << 2 << " " << 1 << "\n";
        return 0;
    }

    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(i+1);
    }

    auto start = st.begin();
    ++start;

    while (st.size() > 1) {
        int val = *start;
        
        cout << val << " ";
        ++start;
        if (start == st.end()) {
            start = st.begin();
        }

        ++start;
        if (start == st.end()) {
            start = st.begin();
        }

        
        st.erase(val);
    }

    auto end = st.end();
    --end;
    cout << *end << "\n";

}