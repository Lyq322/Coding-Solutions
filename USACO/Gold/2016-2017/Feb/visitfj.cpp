#include <bits/stdc++.h>
using namespace std;

struct pii {
	int pos;
	int moves;
};

int N, T;
int grid[100][100] = {{0}};
int di[16] = {0, 1, 0, -1, 2, 2, -1, 1, -1, 1, -2, -2, 3, 0, -3, 0};
int dj[16] = {1, 0, -1, 0, 1, -1, 2, 2, -2, -2, 1, -1, 0, -3, 0, 3};
vector<vector<pair<int, int>>> adj;
int dist[10000] = {0};
bool visited[10000] = {0};

bool operator<(pii a, pii b) {
	return a.moves > b.moves;
}

int main() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < N * N; i++) {
		adj.push_back({});
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 16; k++) {
				int a = i + di[k];
				int b = j + dj[k];
				if (a >= 0 && b >= 0 && a < N && b < N) {
					adj[i * N + j].push_back({a * N + b, 3 * T + grid[a][b]});
				}
			}
		}
	}
	adj[N * N - 2].push_back({N * N - 1, T});
	adj[N * N - N - 1].push_back({N * N - 1, T});
	adj[N * N - 3].push_back({N * N - 1, 2 * T});
	adj[N * N - 2 * N - 1].push_back({N * N - 1, 2 * T});
	adj[N * N - N - 2].push_back({N * N - 1, 2 * T});
	for (int i = 1; i < N * N; i++) {
		dist[i] = -1;
	}
	priority_queue<pii> q;
	q.push({0, 0});
	while (!q.empty()) {
		int cur = q.top().pos;
		int m = q.top().moves;
		q.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int next_move = adj[cur][i].second;
			if (!visited[next] && (dist[next] == -1 || dist[next] > dist[cur] + next_move)) {
				dist[next] = dist[cur] + next_move;
				q.push({next, dist[cur] + next_move});
			}
		}
	}
	cout << dist[N * N - 1] << endl;
}

/*
Create a new graph with edges only between points on the original grid has a distance of 3
Then the weight of those edges would be the endpoint’s weight + 3 * T
However, the number of the moves to the southeast corner might not be a multiple of three, so we need to add some extra edges
*/