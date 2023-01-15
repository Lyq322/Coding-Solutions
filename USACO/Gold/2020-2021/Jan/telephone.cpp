#include <bits/stdc++.h>
using namespace std;

// timeout testcase 8

struct Pos {
	int p;
	int w;
};

bool operator<(Pos a, Pos b) {
	return a.w > b.w;
}

int main() {
	int N, M;
	cin >> N >> M;
	int dist[100000];
	int arr[100000];
	vector<vector<int>> breeds;
	for (int i = 0; i < M; i++) {
		breeds.push_back({});
	}
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i]--;
		breeds[arr[i]].push_back(i);
	}
	int adj[50][50];
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			adj[i][j] = s[j] - '0';
		}
	}
	bool visited[100000] = {0};
	for (int i = 0; i < N; i++) {
		dist[i] = -1;
	}
	dist[0] = 0;
	priority_queue<Pos> q;
	q.push({0, 0});
	while (!q.empty()) {
		int cur = q.top().p;
		q.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		for (int i = 0; i < M; i++) {
			if (adj[arr[cur]][i] == 1) {
				for (int j = 0; j < breeds[i].size(); j++) {
					if (!visited[breeds[i][j]] && (dist[breeds[i][j]] == -1 || dist[breeds[i][j]] > dist[cur] + abs(breeds[i][j] - cur))) {
						dist[breeds[i][j]] = dist[cur] + abs(breeds[i][j] - cur);
						q.push({breeds[i][j], dist[breeds[i][j]]});
					}
				}
			}
		}
	}
	cout << dist[N - 1] << endl;
}
