#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    vector<int> a;

    int n = s.size();
    vector<int> pre(n + 1);

    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i];
        if (s[i] == 't') {
            a.push_back(i);
            pre[i+1]++;
        }
    }


    double ans = 0;
    int m = a.size();
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            // cout << a[j] << " " << pre[j+1] << " ";
            if (a[j] - a[i] + 1 < 3 || pre[a[j]+1] - pre[a[i]] < 2) continue;
            // cout << a[i] << " " << a[j] << endl;
            double cnt = pre[a[j]+1] - pre[a[i]];
            
            ans = max(ans, (cnt - 2) / (a[j] - a[i] - 1));
        }
    }

    cout << fixed << setprecision(18) << ans << endl;
    
}