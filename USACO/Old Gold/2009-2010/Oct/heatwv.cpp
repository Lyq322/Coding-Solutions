#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int T, C, S, E;
vector<vector<pii>> adj;
bool visited[2500] = {0};
int dist[2500];

int main() {
	cin >> T >> C >> S >> E;
	S--;
	E--;
	for (int i = 0; i < T; i++) {
		adj.push_back({});
	}
	int a, b, c;
	for (int i = 0; i < C; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	for (int i = 0; i < T; i++) {
		if (i != S) dist[i] = 1000000000;
		else dist[i] = 0;
	}
	int current = S;
	while (current != -1) {
		for (int i = 0; i < adj[current].size(); i++) {
			int neighbor = adj[current][i].first;
			if (!visited[neighbor]) {
				dist[neighbor] = min(dist[neighbor], dist[current] + adj[current][i].second);
			}
		}
		visited[current] = true;
		current = -1;
		int minimum = -1;
		for (int i = 0; i < T; i++) {
			if (!visited[i] && (minimum == -1 || minimum > dist[i])) {
				minimum = dist[i];
				current = i;
			}
		}
	}
	cout << dist[E] << endl;
}

// Plain dijkstra, nothing else