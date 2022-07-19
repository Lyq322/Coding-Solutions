#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node {
	int pos;
	int w1;
	int w2;
};

bool operator<(Node a, Node b) {
	return a.w1 > b.w1;
}

int main() {
	int N, M;
	cin >> N >> M;
	int a, b, c, d;
	vector<vector<pair<int, int>>> adj;
	vector<vector<Node>> reversed;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
		reversed.push_back({});
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c >> d;
		a--;
		b--;
		reversed[b].push_back({a, c, d});
	}
	int dist[10000];
	int par1[10000];
	bool visited[10000];
	for (int i = 0; i < N; i++) {
		dist[i] = -1;
	}
	dist[N - 1] = 0;
	priority_queue<Node> q;
	q.push({N - 1, 0, 0});
	while (!q.empty()) {
		int cur_pos = q.top().pos;
		q.pop();
		if (visited[cur_pos]) continue;
		visited[cur_pos] = true;
		for (int i = 0; i < reversed[cur_pos].size(); i++) {
			int next_pos = reversed[cur_pos][i].pos;
			int next_weight = reversed[cur_pos][i].w1;
			if (!visited[next_pos] && (dist[next_pos] == -1 || dist[next_pos] > dist[cur_pos] + next_weight)) {
				dist[next_pos] = dist[cur_pos] + next_weight;
				par1[next_pos] = cur_pos;
				q.push({next_pos, dist[next_pos], 0});
			}
		}
	}
	for (int i = 0; i < N; i++) {
		dist[i] = -1;
		visited[i] = false;
	}
	dist[N - 1] = 0;
	q.push({N - 1, 0, 0});
	int par2[10000];
	while (!q.empty()) {
		int cur_pos = q.top().pos;
		q.pop();
		if (visited[cur_pos]) continue;
		visited[cur_pos] = true;
		for (int i = 0; i < reversed[cur_pos].size(); i++) {
			int next_pos = reversed[cur_pos][i].pos;
			int next_weight = reversed[cur_pos][i].w2;
			if (!visited[next_pos] && (dist[next_pos] == -1 || dist[next_pos] > dist[cur_pos] + next_weight)) {
				dist[next_pos] = dist[cur_pos] + next_weight;
				par2[next_pos] = cur_pos;
				q.push({next_pos, dist[next_pos], 0});
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < reversed[i].size(); j++) {
			int t = 2;
			if (par1[reversed[i][j].pos] == i) {
				t--;
			}
			if (par2[reversed[i][j].pos] == i) {
				t--;
			}
			adj[reversed[i][j].pos].push_back({i, t});
		}
	}
	for (int i = 0; i < N; i++) {
		visited[i] = false;
		dist[i] = -1;
	}
	dist[0] = 0;
	q.push({0, 0, 0});
	while (!q.empty()) {
		int cur_pos = q.top().pos;
		q.pop();
		if (visited[cur_pos]) continue;
		visited[cur_pos] = true;
		for (int i = 0; i < adj[cur_pos].size(); i++) {
			int next_pos = adj[cur_pos][i].first;
			int next_weight = adj[cur_pos][i].second;
			if (!visited[next_pos] && (dist[next_pos] == -1 || dist[next_pos] > dist[cur_pos] + next_weight)) {
				dist[next_pos] = dist[cur_pos] + next_weight;
				q.push({next_pos, dist[next_pos], 0});
			}
		}
	}
	cout << dist[N - 1] << endl;
}

/*
Triple dijkstra
1 - Find out best route according to the first GPS
	Reverse the direction of all paths in order to run dijkstra from the finish node
2 - Find out best route according to the second GPS
	Also reverse dir
	Make new graph using info from dijkstra 1 and 2
	This time the graph’s weight is the number of times the GPSs will complain
3 - Dijkstra on new graph to find shortest path or lowest number of complaints 
*/