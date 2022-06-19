#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll V, E, K;
vector<vector<pair<ll, ll>>> adj;
ll dp[50001][11] = {{0}};

ll solve(ll pos, ll m) {
	if (pos == V) {
		return 0;
	}
	else if (dp[pos][m] != -1) {
		return dp[pos][m];
	}
	ll min_fun = 2000000000000000;
	ll max_fun = -1;
	for (ll i = 0; i < adj[pos].size(); i++) {
		max_fun = max(max_fun, solve(adj[pos][i].first, m) + adj[pos][i].second);
        if (m > 0) {
            min_fun = min(min_fun, solve(adj[pos][i].first, m - 1) + adj[pos][i].second);
        }
	}
	dp[pos][m] = min(max_fun, min_fun);
	return dp[pos][m];
}

int main() {
	cin >> V >> E >> K;
	ll a, b, c;
	for (ll i = 0; i < V; i++) {
		adj.push_back({});
	}
	for (ll i = 0; i < V; i++) {
		for (ll j = 0; j <= K; j++) {
			dp[i][j] = -1;
		}
	}
	for (ll i = 0; i < E; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	cout << solve(1, K) << endl;
}

/*
Split into cases: when Bessie goes down a random slide or a chosen slide
We can use top down approach to save time
The result of dp[i][j], where Bessie is at slide i and can still make j mistakes, is the minimum of the two cases since we want the worse cast
For the first case, the total is the minimum of all dp[neighbor][j - 1], and for the second case, the total is the maximum of all dp[neighbor][j]
*/