#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    vector<pair<int, int>> score(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        score[i] = {x, i};
    }

    sort(score.begin(), score.end());
    vector<int> ans(n);

    int r = 1;
    for (int i = n - 1; i >= 0; i--) {
        int k = 1;
        ans[score[i].second] = r;
        int j = i - 1;
        while (j >= 0 && score[j].first == score[i].first) {
            ans[score[j].second] = r;
            k++;
            j--;
        }
        if (j < 0) {
            break;
        } else {
            i = j + 1;
            r += k;
        }
    }

    for (int x : ans) {
        cout << x << "\n";
    }
}