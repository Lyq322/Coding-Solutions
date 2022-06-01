#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M, C;
vector<vector<pii>> adj;
int minimum[100000] = {0};
bool visited[100000] = {0};
vector<int> topo;

void dfs(int node) {
	bool b = true;
	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i].first;
		if (!visited[next]) {
			b = false;
			visited[next] = true;
			dfs(next);
		}
	}
	topo.push_back(node);
}

int main() {
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	int a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> minimum[i];
	}
	for (int i = 0; i < C; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({b, c});
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}
	for (int i = N - 1; i > -1; i--) {
		for (int j = 0; j < adj[topo[i]].size(); j++) {
			minimum[adj[topo[i]][j].first] = max(minimum[adj[topo[i]][j].first], adj[topo[i]][j].second + minimum[topo[i]]);
		}
	}
	for (int i = 0; i < N; i++) {
		cout << minimum[i] << endl;
	}
}

/*
Pseudocode
	Topological sort
	Satisfy the conditions of nodes earlier in the topo vector/array first by looping through the vector/array
	O(V + E)
*/