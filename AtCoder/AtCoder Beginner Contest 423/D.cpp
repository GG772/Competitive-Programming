#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k; cin >> n >> k;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    int sz = 0;
    
    long long t = 0;
    for (int i = 0; i < n; i++) {
        long long a, b, c; cin >> a >> b >> c;
        t = max(t, a);
        while (!pq.empty() && pq.top().first <= t) {
            sz -= pq.top().second;
            pq.pop();
        }
        
        
        while (!pq.empty() && sz + c > k) {
            t = pq.top().first;
            sz -= pq.top().second;
            pq.pop();
        }

        sz += c;

        pq.push({t + b, c});
        cout << t << endl;
    }

    
}