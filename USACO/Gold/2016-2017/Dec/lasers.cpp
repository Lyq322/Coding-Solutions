#include <bits/stdc++.h>
#include <linux/limits.h>
using namespace std;
typedef pair<int, int> pii;

int N, sx, sy, fx, fy;
map<int, int> mx;
map<int, int> my;
pii fence[100000];
bool visited[200004];
vector<vector<int>> adj;

int main() {
	cin >> N >> sx >> sy >> fx >> fy;
	int x[100002];
	int y[100002];
	for (int i = 0; i < N; i++) {
		cin >> fence[i].first >> fence[i].second;
		x[i] = fence[i].first;
		y[i] = fence[i].second;
	}
	x[N] = sx;
	x[N + 1] = fx;
	sort(x, x + N + 2);
	y[N] = sy;
	y[N + 1] = fy;
	int index = 0;
	for (int i = 0; i < N + 2; i++) {
		if (mx.find(x[i]) == mx.end()) {
			mx[x[i]] = index;
			index++;
		}
	}
	index = 0;
	for (int i = 0; i < N + 2; i++) {
		if (my.find(x[i]) == my.end()) {
			my[y[i]] = index;
			index++;
		}
	}
	sx = mx[sx];
	sy = my[sy];
	fx = mx[fx];
	fy = my[fy];
	for (int i = 0; i < 2 * N + 4; i++) {
		adj.push_back({});
	}
	for (int i = 0; i < N; i++) {
		fence[i].first = mx[fence[i].first];
		fence[i].second = my[fence[i].second];
		adj[fence[i].first].push_back(fence[i].second + N + 2);
		adj[fence[i].second + N + 2].push_back(fence[i].first);
	}
	queue<pii> q;
	q.push({sx, 0});
	q.push({sy + N + 2, 0});
	bool found = false;
	while (!q.empty()) {
		int pos = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (pos == fx || pos == fy + N + 2) {
			cout << dist << endl;
			found = true;
			break;
		}
		for (int i = 0; i < adj[pos].size(); i++) {
			int next = adj[pos][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push({next, dist + 1});
			}
		}
	}
	if (!found) cout << -1 << endl;
}

/*
Graph problem if we think of the possible “lines” the laser will travel in as nodes and mirrors as edges
Simple BFS
Need to use coord compression since coords go up to 10^9
*/