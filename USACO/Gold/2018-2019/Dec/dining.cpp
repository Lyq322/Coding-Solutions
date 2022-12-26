#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

/*
First we can find the distance from each cow to the barn using one dijkstra from N
Notice that the tastiness is basically just subtracting that value from the total distance
So to find the shortest path considering tastiness, we can run a multi-source dijkstra starting from each pasture with a haybale
Compare the two distances to get the answer
*/

struct Node {
	int pos;
	int weight;
};

bool operator<(Node a, Node b) {
	return a.weight > b.weight;
}

int main() {
	ifstream fin("dining.in");
	ofstream fout("dining.out");
	int N, M, K;
	fin >> N >> M >> K;
	int a, b, c;
	vector<vector<pii>> adj;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	for (int i = 0; i < M; i++) {
		fin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	vector<pii> haybales;
	for (int i = 0; i < K; i++) {
		fin >> a >> b;
		a--;
		haybales.push_back({a, b});
	}
	priority_queue<Node> q;
	q.push({N - 1, 0});
	bool visited[50000] = {0};
	int dist[50000];
	for (int i = 0; i < N; i++) {
		dist[i] = -1;
	}
	dist[N - 1] = 0;
	while (!q.empty()) {
		int cur = q.top().pos;
		q.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		for (int i = 0; i < adj[cur].size(); i++) {
			pii next = adj[cur][i];
			if (!visited[next.first] && (dist[next.first] == -1 || dist[next.first] > dist[cur] + next.second)) {
				dist[next.first] = dist[cur] + next.second;
				q.push({next.first, dist[next.first]});
			}
		}
	}
	int dist2[50000] = {0};
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < N; i++) {
		dist2[i] = -1;
	}
	for (int i = 0; i < K; i++) {
		q.push({haybales[i].first, dist[haybales[i].first] - haybales[i].second});
		dist2[haybales[i].first] = dist[haybales[i].first] - haybales[i].second;
	}
	while (!q.empty()) {
		int cur = q.top().pos;
		q.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		for (int i = 0; i < adj[cur].size(); i++) {
			pii next = adj[cur][i];
			if (!visited[next.first] && (dist2[next.first] == -1 || dist2[next.first] > dist2[cur] + next.second)) {
				dist2[next.first] = dist2[cur] + next.second;
				q.push({next.first, dist2[next.first]});
			}
		}
	}
	for (int i = 0; i < N - 1; i++) {
		if (dist[i] >= dist2[i]) {
			fout << 1 << endl;
		}
		else {
			fout << 0 << endl;
		}
	}
}
