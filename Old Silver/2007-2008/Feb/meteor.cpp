#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N;
int grid[310][310] = {{0}};
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
bool visited[310][310] = {{0}};

int main() {
	cin >> N;
	for (int i = 0; i < 310; i++) {
		for (int j = 0; j < 310; j++) {
			grid[i][j] = -1;
		}
	}
	int a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (grid[a][b] == -1) grid[a][b] = c;
		else grid[a][b] = min(grid[a][b], c);
		for (int j = 0; j < 4; j++) {
			int d = a + di[j];
			int e = b + dj[j];
			if (d >= 0 && e >= 0 && d < 310 && e < 310) {
				if (grid[d][e] == -1) grid[d][e] = c;
				else grid[d][e] = min(grid[d][e], c);
			}
		}
	}
	queue<pair<pii, int>> q;
	q.push({{0, 0}, 0});
	visited[0][0] = true;
	bool safe = false;
	while (!q.empty()) {
		pii cur = q.front().first;
		int time = q.front().second;
		if (grid[cur.first][cur.second] == -1) {
			safe = true;
			cout << time << endl;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			a = cur.first + di[i];
			b = cur.second + dj[i];
			if (a >= 0 && b >= 0 && a < 310 && b < 310 && !visited[a][b] && (grid[a][b] == -1 || grid[a][b] > time + 1)) {
				visited[a][b] = true;
				q.push({{a, b}, time + 1});
			}
		}
	}
	if (!safe) cout << -1 << endl;
}
