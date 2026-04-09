// https://www.luogu.com.cn/problem/P3952
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l; cin >> l;
    string complexity; cin >> complexity;
    int exp = 0;

    if (complexity[2] == 'n') {
        string t = "";
        int i = 4;
        int n = complexity.size();
        while (i < n && '0' <= complexity[i] && complexity[i] <= '9') {
            t.push_back(complexity[i]);
            i++;
        }
        exp = stoi(t);
    }

    stack<pair<string, int>> st; // store a pair of var, complexity
    map<string, int> mp; // store created var names
    int cur = 0;
    int cnt = 0;
    int ans = 0;
    bool f = true;

    map<string, bool> is_valid; // check whether a loop execute or note
    for (int i = 0; i < l; i++) {
        string s; cin >> s;
        if (s == "F") {
            cnt++;
            string var, start, end; cin >> var >> start >> end;
            // atmost constant complexity
            int t; 
            
            if (start == "n" || end != "n") {
                st.push({var, 0});
                t = 0;
            } else {
                cur++;
                st.push({var, 1});
                t = 1;
            }
            if (mp.count(var)) f = false;
            mp[var] = true;
            ans = max(ans, cur);
        } else {
            cnt--;
            auto [v, c] = st.top();
            st.pop();
            mp.erase(v);
            cur -= c;
        }
        
        if (cnt < 0) f = false;
    }

    if (!f || cnt != 0) cout << "ERR\n"; 
    else {
        if (ans <= exp) cout << "Yes\n";
        else {
            cout << "Computed: " << ans << " expect " << exp << endl;
            cout << "No\n";
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}