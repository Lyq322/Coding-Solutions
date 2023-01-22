#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
ll ans[100001];
ll max_depth = 0;
ll N;

int dfs(ll pos, ll x, ll cur_d) {
	ans[pos] = x + (max_depth - cur_d) * (N + 1);
	for (int i = adj[pos].size() - 1; i > -1; i--) {
		x--;
		x = dfs(adj[pos][i], x, cur_d + 1);
	}
	return x;
}

void height(ll pos, ll h) {
	for (int i = 0; i < adj[pos].size(); i++) {
		height(adj[pos][i], h + 1);
	}
	max_depth = max(max_depth, h);
}

int main() {
	cin >> N;
	for (int i = 0; i <= N; i++) {
		adj.push_back({});
	}
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		adj[a].push_back(i);
	}
	height(N, 0);
	dfs(N, N, 0);
	cout << N + 1 << endl;
	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}
}
