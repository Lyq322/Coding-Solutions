#include <bits/stdc++.h>
using namespace std;

// MST with nodes being the portals and edges = 0 if 2 portals are p1 p2 or p3 p4 of a vertex and = moony for everything else

struct Pos {
	int p;
	int w;
};

bool operator<(Pos a, Pos b) {
	return a.w > b.w;
}

int main() {
	int N;
	cin >> N;
	vector<vector<pair<int, int>>> edges;
	for (int i = 0; i < 2 * N; i++) {
		edges.push_back({});
	}
	int m;
	int a, b, c, d;
	for (int i = 0; i < N; i++) {
		cin >> m;
		cin >> a >> b >> c >> d;
		a--;
		b--;
		c--;
		d--;
		edges[a].push_back({b, 0});
		edges[b].push_back({a, 0});
		edges[c].push_back({d, 0});
		edges[d].push_back({c, 0});
		edges[a].push_back({c, m});
		edges[a].push_back({d, m});
		edges[b].push_back({c, m});
		edges[b].push_back({d, m});
		edges[c].push_back({a, m});
		edges[c].push_back({b, m});
		edges[d].push_back({a, m});
		edges[d].push_back({b, m});
	}
	int dist[200000];
	for (int i = 1; i < 2 * N; i++) {
		dist[i] = -1;
	}
	dist[0] = 0;
	bool visited[200000] = {0};
	priority_queue<Pos> q;
	q.push({0, 0});
	while (!q.empty()) {
		int cur = q.top().p;
		q.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		for (int i = 0; i < edges[cur].size(); i++) {
			pair<int, int> next = edges[cur][i];
			if (!visited[next.first] && (dist[next.first] == -1 || dist[next.first] > next.second)) {
				dist[next.first] = next.second;
				q.push({next.first, next.second});
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 2 * N; i++) {
		ans += dist[i];
	}
	cout << ans << endl;
}
