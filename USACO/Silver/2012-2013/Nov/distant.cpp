#include <bits/stdc++.h>
using namespace std;

struct Node {
	int x;
	int y;
	int weight;
};

bool operator<(Node a, Node b) {
	return a.weight > b.weight;
}

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	char field[40][40];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> field[i][j];
		}
	}
	int di[4] = {0, 1, -1, 0};
	int dj[4] = {1, 0, 0, -1};
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			priority_queue<Node> q;
			q.push({i, j, 0});
			bool visited[40][40] = {{0}};
			int dist[40][40];
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					dist[k][l] = -1;
				}
			}
			dist[i][j] = 0;
			while (!q.empty()) {
				int x = q.top().x;
				int y = q.top().y;
				q.pop();
				if (visited[x][y]) continue;
				visited[x][y] = true;
				for (int k = 0; k < 4; k++) {
					int a = di[k] + x;
					int b = dj[k] + y;
					if (a >= 0 && b >= 0 && a < N && b < N && !visited[a][b]) {
						int weight;
						if (field[a][b] == field[x][y]) weight = A;
						else weight = B;
						if (dist[a][b] == -1 || dist[a][b] > dist[x][y] + weight) {
							dist[a][b] = dist[x][y] + weight;
							q.push({a, b, dist[a][b]});
						}
					}
				}
			}
			int maximum = 0;
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					maximum = max(maximum, dist[k][l]);
				}
			}
			ans = max(ans, maximum);
		}
	}
	cout << ans << endl;
}

//Run Dijkstra on all nodes O(N^4logN^2)