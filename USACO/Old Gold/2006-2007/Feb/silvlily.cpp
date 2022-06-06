#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
	ll w;
	ll p;
	ll m;
};

ll grid[30][30] = {{0}};
vector<vector<pair<ll, ll>>> adj;
ll di[8] = {1, 1, -1, -1, 2, 2, -2, -2};
ll dj[8] = {2, -2, 2, -2, 1, -1, 1, -1};
ll sx, sy, fx, fy;
ll dist[900] = {0};
ll total_moves[900] = {0};
ll min_moves[900] = {0};
bool visited[900] = {0};

bool operator<(Node a, Node b) {
	if (a.w == b.w) {
		return a.m > b.m;
	}
	return a.w > b.w;
}

int main() {
	ll N, M;
	cin >> N >> M;
	for (ll i = 0; i < N * M; i++) {
		adj.push_back({});
	}
	ll a, b;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 3) {
				sx = i;
				sy = j;
			}
			else if (grid[i][j] == 4) {
				fx = i;
				fy = j;
			}
		}
	}
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			for (ll k = 0; k < 8; k++) {
				a = i + di[k];
				b = j + dj[k];
				if (a >= 0 && b >= 0 && a < N && b < M) {
					if (grid[a][b] == 0) {
						adj[i * M + j].push_back({a * M + b, 1});
					}
					else if (grid[a][b] == 1 || grid[a][b] == 4) {
						adj[i * M + j].push_back({a * M + b, 0});
					}
				}
			}
		}
	}
	for (ll i = 0; i < N * M; i++) {
		if (i != sx * M + sy) {
			dist[i] = -1;
			min_moves[i] = -1;
		}
	}
	priority_queue<Node> q;
	q.push({0, sx * M + sy, 0});
	total_moves[sx * M + sy] = 1;
	while (!q.empty()) {
		ll pos = q.top().p;
		ll weight = q.top().w;
		ll moves = q.top().m;
		q.pop();
		if (visited[pos]) continue;
		visited[pos] = true;
		for (ll i = 0; i < adj[pos].size(); i++) {
			ll next_w = adj[pos][i].second;
			ll next = adj[pos][i].first;
			if (dist[next] == -1 || dist[next] >= dist[pos] + next_w) {
				if (min_moves[next] == -1 || min_moves[next] > moves + 1) {
					min_moves[next] = moves + 1;
					total_moves[next] = total_moves[pos];
				}
				else if (min_moves[next] == moves + 1) {
					total_moves[next] += total_moves[pos];
				}
			}
			if (!visited[next] && (dist[next] == -1 || dist[next] > dist[pos] + next_w)) {
				dist[next] = dist[pos] + next_w;
				q.push({dist[pos] + next_w, next, moves + 1});
			}
		}
	}
	cout << dist[fx * M + fy] << endl;
	if (dist[fx * M + fy] != -1) {
    	cout << min_moves[fx * M + fy] << endl;
    	cout << total_moves[fx * M + fy] << endl;
	}
}

/*
Similar idea to Why Did the Cow Cross the Road (Gold)
Create a new graph with edges that connected nodes that can be reached with one “knight” move
Use dijkstra to traverse the graph
Number of moves to reach endpoint can be tracked using an array
	Number of moves to reach point n is the sum of the number of ways to reach the neighbors of n
	Need to keep track of the smallest distance
	Dp-ish
	Similar to counting the number of paths in a grid in math
*/