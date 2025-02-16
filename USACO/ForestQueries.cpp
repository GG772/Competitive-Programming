// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q; cin >> n >> q;

	vector<vector<int>> arr(n+1, vector<int>(n+1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c; cin >> c;
			arr[i][j] = (c == '*');
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		}
	}

	for (int i = 0; i < q; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1;
		cin >> y2 >> x2;

		// cout << arr[x2][y2] << " " << arr[x1][y2] << " " << arr[x2][y1] << " " << arr[x1][y1] << " ";

		cout << arr[y2][x2] - arr[y1-1][x2] - arr[y2][x1-1] + arr[y1-1][x1-1] << endl;
	}
}
