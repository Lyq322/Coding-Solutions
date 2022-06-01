#include <bits/stdc++.h>
using namespace std;

struct pii {
	int first;
	int second;
};

int N, M;
vector<vector<pii>> adj;
bool visited[50000] = {0};
int dist[50000] = {0};

bool operator<(pii a, pii b) {
	return a.first > b.first;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	for (int i = 1; i < N; i++) {
		dist[i] = -1;
	}
	priority_queue<pii> q;
	q.push({0, 0});
	while (!q.empty()) {
		int cur = q.top().second;
		int w = q.top().first;
		q.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		for (int i = 0; i < adj[cur].size(); i++) {
			pii next = adj[cur][i];
			if (!visited[next.first] && (dist[next.first] == -1 || dist[next.first] > w + next.second)) {
				dist[next.first] = w + next.second;
				q.push({w + next.second, next.first});
			}
		}
	}
	cout << dist[N - 1] << endl;
}
