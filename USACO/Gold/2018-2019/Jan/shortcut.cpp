#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

struct Node {
	ll pos;
	ll dist;
	ll parent;
	ll path;
};

bool operator<(Node a, Node b) {
	if (a.dist == b.dist) {
		if (a.path == b.path) {
			return a.parent > b.parent;
		}
		return a.path > b.path;
	}
	return a.dist > b.dist;
}

ll N, M, T;
ll cows[10000];
vector<vector<pii>> adj;
vector<vector<ll>> tree;
bool visited[10000] = {0};
ll dp2[10000] = {0};
ll dist[10000];
ll parent[10000];

ll dp(ll pos) {
	if (dp2[pos] != -1) return dp2[pos];
	dp2[pos] = 0;
	for (ll i = 0; i < tree[pos].size(); i++) {
		ll next = tree[pos][i];
		dp2[pos] += dp(next);
	}
	dp2[pos] += cows[pos];
	return dp2[pos];
}

int main() {
	cin >> N >> M >> T;
	for (ll i = 0; i < N; i++) {
		cin >> cows[i];
		adj.push_back({});
		tree.push_back({});
	}
	ll a, b, c;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	priority_queue<Node> q;
	q.push({0, 0, 0, 0});
	for (ll i = 1; i < N; i++) dist[i] = -1;
	dist[0] = 0;
	while (!q.empty()) {
		ll cur_pos = q.top().pos;
		ll cur_dist = q.top().dist;
		ll cur_path = q.top().path;
		ll cur_par = q.top().parent;
		q.pop();
		if (visited[cur_pos]) continue;
		visited[cur_pos] = true;
		parent[cur_pos] = cur_par;
		for (ll i = 0; i < adj[cur_pos].size(); i++) {
			ll next_pos = adj[cur_pos][i].first;
			ll next_dist = adj[cur_pos][i].second;
			if (!visited[next_pos] && (dist[next_pos] == -1 || next_dist + cur_dist <= dist[next_pos])) {
				dist[next_pos] = next_dist + cur_dist;
				q.push({next_pos, dist[next_pos], cur_pos, cur_path + 1});
			}
		}
	}
	dp2[0] = -1;
	for (ll i = 1; i < N; i++) {
		dp2[i] = -1;
		tree[parent[i]].push_back(i);
	}
	dp(0);
	ll ans = 0;
	for (ll i = 0; i < N; i++) {
		if (dist[i] - T > 0) ans = max(ans, (dist[i] - T) * dp2[i]);
	}
	cout << ans << endl;
}

/*
We need to find the number of cows that pass through a node (when using the lexicographically shortest path) to find the answer
Shortest path means dijkstra’s, this time saving the parent nodes in an array
We can use that array to create a shortest path tree
Using dfs tree dp, we can find the # of cows passing through each node
*/