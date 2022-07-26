#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int B, E, P, N, M;
	cin >> B >> E >> P >> N >> M;
	vector<vector<int>> adj;
	for (int i = 0; i < N; i++) adj.push_back({});
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<pii> q;
	q.push({0, 0});
	bool visited[40000] = {0};
	int dist1[40000] = {0};
	int dist2[40000] = {0};
	int distN[40000] = {0};
	visited[0] = true;
	while (!q.empty()) {
		int pos = q.front().first;
		int dist = q.front().second;
		q.pop();
		for (int i = 0; i < adj[pos].size(); i++) {
			int next = adj[pos][i];
			if (!visited[next]) {
				visited[next] = true;
				dist1[next] = dist + 1;
				q.push({next, dist + 1});
			}
		}
	}
	for (int i = 0; i < N; i++) visited[i] = false;
	visited[1] = true;
	q.push({1, 0});
	while (!q.empty()) {
		int pos = q.front().first;
		int dist = q.front().second;
		q.pop();
		for (int i = 0; i < adj[pos].size(); i++) {
			int next = adj[pos][i];
			if (!visited[next]) {
				visited[next] = true;
				dist2[next] = dist + 1;
				q.push({next, dist + 1});
			}
		}
	}
	for (int i = 0; i < N; i++) visited[i] = false;
	visited[N - 1] = true;
	q.push({N - 1, 0});
	while (!q.empty()) {
		int pos = q.front().first;
		int dist = q.front().second;
		q.pop();
		for (int i = 0; i < adj[pos].size(); i++) {
			int next = adj[pos][i];
			if (!visited[next]) {
				visited[next] = true;
				distN[next] = dist + 1;
				q.push({next, dist + 1});
			}
		}
	}
	int ans = 2000000000;
	for (int i = 0; i < N; i++) {
		int t = dist1[i] * B + dist2[i] * E + distN[i] * P;
		ans = min(ans ,t);		
	}
	cout << ans << endl;
}

/*
Let the node where bessie and elsie meet to piggyback be K
Notice that after K bessie and elsie will always piggyback until they reach N
We can loop over K and precompute the distance from nodes 1, 2, and N to all other nodes to run in O(N)
*/