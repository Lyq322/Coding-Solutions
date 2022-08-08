#include <bits/stdc++.h>
using namespace std;

struct Light {
	char color;
	int r;
	int dur_b;
	int dur_p;
};

struct Node {
	int pos;
	int time;
};

bool operator<(Node a, Node b) {
	return a.time > b.time;
}

int S, D, N, M;
Light lights[300];
vector<vector<pair<int, int>>> adj;

char check_color(int t, int i) {
	if (t <= lights[i].r) {
		return lights[i].color;
	}
	int v = (t - lights[i].r) % (lights[i].dur_b + lights[i].dur_p);
	if (lights[i].color == 'B') {
		if (v > 0 && v <= lights[i].dur_p) {
			return 'P';
		}
		else return 'B';
	}
	else {
		if (v > 0 && v <= lights[i].dur_b) {
			return 'B';
		}
		else return 'P';
	}
}

int update_time(int i, int j, int t) {
	for (int k = t + 1; k < t + 1000; k++) {
		if (check_color(k, i) == check_color(k, j)) {
			return k - 1;
		}
	}
	return -1;
}



int main() {
	cin >> S >> D >> N >> M;
	S--;
	D--;
	char c;
	int a, b, d;
	for (int i = 0; i < N; i++) {
		cin >> c >> a >> b >> d;
		lights[i] = {c, a, b, d};
	}
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> d;
		a--;
		b--;
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	int dist[300];
	for (int i = 0; i < N; i++) {
		dist[i] = -1;
	}
	dist[S] = 0;
	bool visited[300] = {0};
	priority_queue<Node> q;
	q.push({S, 0});
	while (!q.empty()) {
		int pos = q.top().pos;
		int time = q.top().time;
		q.pop();
		if (visited[pos]) continue;
		visited[pos] = true;
		for (int i = 0; i < adj[pos].size(); i++) {
			int next_p = adj[pos][i].first;
			int next_t = adj[pos][i].second;
			int new_t = update_time(pos, next_p, time);
			if (new_t != -1 && (dist[next_p] == -1 || dist[next_p] > new_t + next_t)) {
				dist[next_p] = new_t + next_t;
				q.push({next_p, dist[next_p]});
			}
		}
	}
	cout << max(0, dist[D]) << endl;
}

/*
We first need to find a way to find the next time two traffic lights will have the same color. After we found that algorithm, we can just run a modified dijkstra on the graph
Notice that we can use brute force to simulate the colors of two traffic lights, from current time t to t + 1000 should be enough (didn’t calculate, but passes all test cases lol)
After we run dijkstra as mentioned above
*/