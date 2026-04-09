#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<int> pts(n+1);

    vector<string> votes;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        votes.push_back(s);
    }

    for (int i = 0; i < m; i++) {
        int cnt0 = 0, cnt1 = 0;
        for (int j = 0; j < n; j++) {
            char c = votes[j][i];
            cnt0 += (c == '0');
            cnt1 += (c == '1');
        }

        for (int j = 0; j < n; j++) {
            char c = votes[j][i];
            if (cnt0 > cnt1 && c == '1') {
                pts[j+1]++;
            } else if (cnt1 > cnt0 && c == '0') {
                pts[j+1]++;
            } else if (cnt0 == cnt1) {
                pts[j+1]++;
            }
        }
    }

    int mx = *max_element(pts.begin(), pts.end());
    for (int i = 1; i <= n; i++) {
        if (pts[i] == mx) cout << i << " ";
    }
    
}