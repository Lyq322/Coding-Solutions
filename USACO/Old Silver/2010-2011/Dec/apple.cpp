#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int C, P, Pb, Pa1, Pa2;
vector<vector<pii>> adj;

struct Cow {
	int pos;
	int weight;
};

bool operator<(Cow a, Cow b) {
	return a.weight > b.weight;
}

int dijkstra(int s, int f) {
	int dist[200000];
	for (int i = 0; i < P; i++) dist[i] = -1;
	dist[s] = 0;
	bool visited[200000] = {0};
	priority_queue<Cow> q;
	q.push({s, 0});
	while (!q.empty()) {
		Cow c = q.top();
		q.pop();
		if (visited[c.pos]) continue;
		visited[c.pos] = true;
		for (int i = 0; i < adj[c.pos].size(); i++) {
			pii next = adj[c.pos][i];
			if (!visited[next.first] && (dist[next.first] == -1 || dist[next.first] > dist[c.pos] + next.second)) {
				dist[next.first] = dist[c.pos] + next.second;
				q.push({next.first, dist[next.first]});
			}
		}
	}
	return dist[f];
}

int main() {
	cin >> C >> P >> Pb >> Pa1 >> Pa2;
	Pb--;
	Pa1--;
	Pa2--;
	int a, b, c;
	for (int i = 0; i < P; i++) adj.push_back({});
	for (int i = 0; i < C; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	int apples = dijkstra(Pa1, Pa2);
	int a1_dist = dijkstra(Pb, Pa1);
	int a2_dist = dijkstra(Pb, Pa2);
	cout << min(a1_dist, a2_dist) + apples << endl;
}

// Run dijkstra to cal dist from a1 to a2, b to a1 and b to a2
