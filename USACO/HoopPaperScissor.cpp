// Source: https://usaco.guide/general/io
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=691

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hps.in", "r", stdin);
	int n; cin >> n;
	cin.ignore();

	char arr[n];

	vector<int> pre1(n+1), pre2(n+1), pre3(n+1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		pre1[i] = pre1[i-1];
		pre2[i] = pre2[i-1];
		pre3[i] = pre3[i-1];
		if (arr[i-1] == 'S') {
			pre1[i]++;
		} else if (arr[i-1] == 'P') {
			pre2[i]++;
		} else {
			pre3[i]++;
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		int before = max({pre1[i], pre2[i], pre3[i]});
		int after = max({pre1[n] - pre1[i], pre2[n] - pre2[i], pre3[n] - pre3[i]});
		ans = max(ans, before + after);
	}

	freopen("hps.out", "w", stdout);

	cout << ans << "\n";



	
}
