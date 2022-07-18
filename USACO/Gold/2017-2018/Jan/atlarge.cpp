#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> adj;
bool visited[100000] = {0};
int min_dist[100000] = {0};
int cur_dist[100000] = {0};
int farmers = 0;

int dfs(int pos, int dist) {
	int d = -1;
	for (int i = 0; i < adj[pos].size(); i++) {
		if (!visited[adj[pos][i]]) {
			visited[adj[pos][i]] = true;
			int a = dfs(adj[pos][i], dist + 1);
			if (d == -1 || d > a) d = a;
		}
	}
	min_dist[pos] = max(dist, d);
	cur_dist[pos] = dist;
	return max(dist, d);
}

void dfs2(int pos) {
	if (min_dist[pos] - cur_dist[pos] <= cur_dist[pos]) {
		farmers++;
		return;
	}
	for (int i = 0; i < adj[pos].size(); i++) {
		if (!visited[adj[pos][i]]) {
			visited[adj[pos][i]] = true;
			dfs2(adj[pos][i]);
		}
	}
}

int main() {
	cin >> N >> K;
	int a, b;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	visited[K - 1] = true;
	dfs(K - 1, 0);
	for (int i = 0; i < N; i++) visited[i] = false;
	visited[K - 1] = true;
	dfs2(K - 1);
	cout << farmers << endl;
}

/*
For every node, we want to find the distance to the closest exit node, or a leaf in a tree
	Dfs
At any node, if the shortest distance from a leaf to the current node is less than or equal to the distance from the root to the current node, then one farmer will be enough
Using the observation above, a second dfs can be used to find the answer
*/