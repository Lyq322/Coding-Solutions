#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
vector<vector<int>> adj;

void check(int start, int end) {
	queue<int> q;
	q.push(start);
	bool visited[1000] = {0};
	visited[start] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == end) {
			cout << "Y" << endl;
			return;
		}
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	cout << "N" << endl;
	return;
}

int main() {
	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		a--;
		b--;
		check(a, b);
	}
}

/*
Solution 1 - BFS/DFS
	Pseudocode
	Check every pair using DFS/BFS
	O(V + E)
Solution 2 - Floyd-Warshall
	O(N^3)
*/