#include <bits/stdc++.h>

using namespace std;

using ll = long long;
void solve() {
    int n, m; cin >> n >> m;
    ll inf = 1e14;

    vector<vector<ll>> dp(n, vector<ll>(n, inf));

    // build graph, and then
    
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
    }

    // run floyd warshall
    ll tot = 0;

    for (int i = 0; i < n; i++) dp[i][i] = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] != inf) tot += dp[i][j];
        }
    }

    int K, T; cin >> K >> T;
    
    vector<bool> airport(n);

    for (int i = 0; i < K; i++) {
        int x; cin >> x;
        airport[x-1] = true;
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int x, y;
            ll t; // Changed to ll
            cin >> x >> y >> t;
            x--, y--;
            
            // If the new road is shorter, update the road-only distance matrix
            if (dp[x][y] > t) {
                dp[x][y] = t;
                dp[y][x] = t;
                
                // Perform the O(N^2) incremental update for the new road
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        // The path might be shorter via x -> y or y -> x
                        dp[i][j] = min({dp[i][j], dp[i][x] + dp[x][y] + dp[y][j], dp[i][y] + dp[y][x] + dp[x][j]});
                    }
                }
            }

        } else if (cmd == 2) {
            int x; cin >> x;
            x--;
            // CORRECTED: Just mark the city as having an airport.
            // The road network itself doesn't change.
            airport[x] = true;
        
        } else { // cmd == 3
            // CORRECTED: Calculate the sum from scratch.
            
            // Step 1: Find the shortest distance from each city to an airport
            vector<ll> dist_to_airport(n, inf);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (airport[j]) {
                        dist_to_airport[i] = min(dist_to_airport[i], dp[i][j]);
                    }
                }
            }

            // Step 2: Calculate the total sum
            ll total_sum = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Path using roads only
                    ll road_path = dp[i][j];

                    // Path using an airport trip
                    ll airport_path = inf;
                    if (dist_to_airport[i] != inf && dist_to_airport[j] != inf) {
                       airport_path = dist_to_airport[i] + T + dist_to_airport[j];
                    }
                    
                    ll final_dist = min(road_path, airport_path);

                    if (final_dist < inf) {
                        total_sum += final_dist;
                    }
                }
            }
            cout << total_sum << "\n";
        }
    }
}

int main() {
    int t; t = 1;
    while (t--) solve();
}   