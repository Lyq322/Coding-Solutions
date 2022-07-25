#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Node {
	int pos;
	int weight;
};

bool operator<(Node a, Node b) {
	return a.weight > b.weight;
}

int main() {
	int N;
	cin >> N;
	int arr[2000];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int adj[2000][2000];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) adj[i][j] = -1;
			else {
				adj[i][j] = arr[i] ^ arr[j];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			adj[i][j] = 0 - adj[i][j];
		}
	}
	priority_queue<Node> q;
	q.push({0, 0});
	int dist[2000];
	for (int i = 0; i < N; i++) {
		dist[i] = 1;
	}
	dist[0] = 0;
	bool visited[2000] = {0};
	while (!q.empty()) {
		int pos = q.top().pos;
		q.pop();
		if (visited[pos]) continue;
		visited[pos] = true;
		for (int i = 0; i < N; i++) {
			if (i != pos) {
				if (!visited[i] && (dist[i] == 1 || dist[i] > adj[pos][i])) {
					dist[i] = adj[pos][i];
					q.push({i, dist[i]});
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		ans += 0 - dist[i];
	}
	cout << ans << endl;
}

// Maximum spanning tree by negating the edge weights
