#include <bits/stdc++.h>
using namespace std;

struct Node {
	int first;
	int second;
	int weight;
};

bool operator<(Node a, Node b) {
	return a.weight > b.weight;
}

int main() {
	int A, B, N, M;
	cin >> A >> B >> N >> M;
	int prev = 0;
	int vertical[2000];
	int horizontal[2000];
	int di[4] = {0, 1, 0, -1};
	int dj[4] = {1, 0, -1, 0};
	for (int i = 0; i < N; i++) {
		cin >> vertical[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> horizontal[i];
	}
	vertical[N] = 0;
	vertical[N + 1] = A;
	horizontal[M] = 0;
	horizontal[M + 1] = B;
	sort(vertical, vertical + N + 2);
	sort(horizontal, horizontal + M + 2);
	int dist[2001][2001];
	bool visited[2001][2001] = {{0}};
	for (int i = 0; i < 2001; i++) {
		for (int j = 0; j < 2001; j++) {
			dist[i][j] = -1;
		}
	}
	dist[0][0] = 0;
	priority_queue<Node> q;
	q.push({0, 0});
	while (!q.empty()) {
		pair<int, int> pos = {q.top().first, q.top().second};
		int weight = q.top().weight;
		q.pop();
		if (visited[pos.first][pos.second]) continue;
		visited[pos.first][pos.second] = true;
		for (int i = 0; i < 4; i++) {
			int a = pos.first + di[i];
			int b = pos.second + dj[i];
			if (a >= 0 && b >= 0 && a <= M && b <= N) {
				int new_weight;
				if (i == 0 || i == 2) {
					new_weight = horizontal[a + 1] - horizontal[a];
				}
				else {
					new_weight = vertical[b + 1] - vertical[b];
				}
				if (!visited[a][b] && (dist[a][b] == -1 || dist[a][b] > new_weight)) {
					dist[a][b] = new_weight;
					q.push({a, b, new_weight});
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			ans += dist[i][j];
		}
	}
	cout << ans << endl;
}

// This problem can be thought of an MST problem — find the least number of fences needed to connect all nodes
